#include "OpenGLWidget.h"

#include <QFileDialog>

namespace s21 {
OpenGLWidget::OpenGLWidget(QWidget *parent, AffineFacade *affine)
    : QOpenGLWidget(parent), affine_(affine) {
  index_array_ = new std::vector<GLuint>();
  type_line_ = kSolid;
  model_ = Model::GetInstance();
  type_vertex_ = kNone;
  type_projection_ = kOrthogonal;
  color_background_ = QColor(0, 0, 0);
  color_lines_ = QColor(255, 255, 255);
  line_thickness_ = 1;
  vertex_size_ = 10;
  prev_type_projection_ = kOrthogonal;
  color_vertex_ = QColor(155, 155, 255);
}

void OpenGLWidget::paintGL() {
  if (model_ != nullptr && !model_->GetPolygons()->empty()) {
    ChangeProjection();
    glClearColor(color_background_.redF(), color_background_.greenF(),
                 color_background_.blueF(), 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glEnableClientState(GL_VERTEX_ARRAY);
    affine_->DoAffine();
    glLineWidth(line_thickness_);
    glVertexPointer(3, GL_DOUBLE, 0, model_->GetCoordinates()->data());
    DrawVertexes();
    CreatePolygons();
    glLineWidth(line_thickness_);
    glColor3f(color_lines_.redF(), color_lines_.greenF(), color_lines_.blueF());
    if (type_line_ == kDashed) {
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(1, 0x3333);
    } else {
      glDisable(GL_LINE_STIPPLE);
    }
    glDrawElements(GL_LINES, index_array_->size(), GL_UNSIGNED_INT,
                   index_array_->data());
    glDisableClientState(GL_VERTEX_ARRAY);
    index_array_->clear();
    affine_->UpdatePrevValues();
  }
}

void OpenGLWidget::CreatePolygons() {
  auto &polygons = *model_->GetPolygons();
  for (auto &current_polygon : polygons) {
    for (size_t j = 0; j < current_polygon.size() - 1; ++j) {
      index_array_->push_back(current_polygon[j]);
      index_array_->push_back(current_polygon[j + 1]);
    }
    index_array_->push_back(current_polygon.back());
    index_array_->push_back(current_polygon.front());
  }
}

void OpenGLWidget::initializeGL() { QOpenGLWidget::initializeGL(); }

void OpenGLWidget::resizeGL(int w, int h) { QOpenGLWidget::resizeGL(w, h); }

OpenGLWidget::~OpenGLWidget() { delete index_array_; }

void OpenGLWidget::ChangeProjection() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  float fov = 60.0 * M_PI / 180;
  float heapHeight = 1 / (2 * std::tan(fov / 2));
  if (type_projection_ == kCentral) {
    glFrustum(-1, 1, -1, 1, heapHeight, 99999);
    if (prev_type_projection_ == kOrthogonal) {
      affine_->CenterCoordinates();
      //      affine_->MoveZ(-heapHeight * 3.0);
    }
  } else if (type_projection_ == kOrthogonal) {
    if (prev_type_projection_ == kCentral) {
      affine_->CenterCoordinates();
    }
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 99999);
  }
  prev_type_projection_ = type_projection_;
}

void OpenGLWidget::SaveImage() {
  QImage image = this->grabFramebuffer();
  QString selectedFilter;
  QString file_name = QFileDialog::getSaveFileName(
      this, "Save image", " ", ".bmp;;.jpeg", &selectedFilter);
  if (!file_name.isEmpty()) {
    image.save(file_name.remove(" ") + selectedFilter);
  }
}

void OpenGLWidget::DrawVertexes() {
  if (type_vertex_ != kNone) {
    glPointSize(vertex_size_);
    glColor3f(color_vertex_.redF(), color_vertex_.greenF(),
              color_vertex_.blueF());
    if (type_vertex_ == kCircle) {
      glEnable(GL_POINT_SMOOTH);
      glDrawArrays(GL_POINTS, 1, *model_->GetCountOfVertexes() - 1);
      glDisable(GL_POINT_SMOOTH);
    } else {
      glDrawArrays(GL_POINTS, 1, *model_->GetCountOfVertexes() - 1);
    }
  }
}
}  // namespace s21
