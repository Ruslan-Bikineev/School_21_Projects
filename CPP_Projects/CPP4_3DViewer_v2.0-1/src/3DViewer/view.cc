#include "view.h"

#include "ui_view.h"
namespace s21 {
View::View(QWidget *parent, s21::Controller *controller)
    : QMainWindow(parent), ui_(new Ui::View), controller_(controller) {
  ui_->setupUi(this);
  QCoreApplication::setOrganizationName("Dream team");
  QCoreApplication::setApplicationName("3DViewer_v2.0");
  open_gl_widget_ = new OpenGLWidget(ui_->widgetGl, affine_);
  ui_->widgetGl->setLayout(new QVBoxLayout());
  ui_->widgetGl->layout()->addWidget(open_gl_widget_);
  frame_timer_ = new QTimer(this);
  stop_timer_ = new QTimer(this);

  connect(ui_->save_image, SIGNAL(clicked()), this, SLOT(SaveImage()));
  connect(ui_->import_file, SIGNAL(clicked()), this, SLOT(ImportFile()));
  connect(ui_->start_record, SIGNAL(clicked()), this, SLOT(StartRecord()));
  connect(ui_->save_settings, SIGNAL(clicked()), this, SLOT(SaveSettings()));
  connect(ui_->load_settings, SIGNAL(clicked()), this, SLOT(LoadSettings()));
  connect(ui_->radio_lines_solid, SIGNAL(clicked()), this, SLOT(LinesSolid()));
  connect(ui_->choose_lines_color, SIGNAL(clicked()), this, SLOT(ColorLines()));
  connect(ui_->radio_lines_dashed, SIGNAL(clicked()), this,
          SLOT(LinesDashed()));
  connect(ui_->choose_vertex_color, SIGNAL(clicked()), this,
          SLOT(ColorVertex()));
  connect(ui_->choose_background_color, SIGNAL(clicked()), this,
          SLOT(ColorBackground()));
  connect(ui_->radio_projection_central, SIGNAL(clicked()), this,
          SLOT(ProjectionCentral()));
  connect(ui_->radio_display_method_none, SIGNAL(clicked()), this,
          SLOT(DisplayMethodNone()));
  connect(ui_->radio_display_method_square, SIGNAL(clicked()), this,
          SLOT(DisplayMethodSquare()));
  connect(ui_->radio_display_method_circle, SIGNAL(clicked()), this,
          SLOT(DisplayMethodCircle()));
  connect(ui_->radio_projection_orthogonal, SIGNAL(clicked()), this,
          SLOT(ProjectionOrthogonal()));
  connect(ui_->move_x, QOverload<int>::of(&QSlider::valueChanged), this,
          [this](int value) { MoveX(value); });
  connect(ui_->move_y, QOverload<int>::of(&QSlider::valueChanged), this,
          [this](int value) { MoveY(value); });
  connect(ui_->move_z, QOverload<int>::of(&QSlider::valueChanged), this,
          [this](int value) { MoveZ(value); });
  connect(ui_->rotate_x, QOverload<int>::of(&QSlider::valueChanged), this,
          [this](int value) { RotateX(value); });
  connect(ui_->rotate_y, QOverload<int>::of(&QSlider::valueChanged), this,
          [this](int value) { RotateY(value); });
  connect(ui_->rotate_z, QOverload<int>::of(&QSlider::valueChanged), this,
          [this](int value) { RotateZ(value); });
  connect(ui_->scale, QOverload<int>::of(&QSlider::valueChanged), this,
          [this](int value) { ScaleValue(value); });
  connect(ui_->vertexes_size, QOverload<int>::of(&QSlider::valueChanged), this,
          [this](int value) { VertexesSize(value); });
  connect(ui_->lines_thickness, QOverload<int>::of(&QSlider::valueChanged),
          this, [this](int value) { LinesThickness(value); });
}

View::~View() {
  delete ui_;
  delete affine_;
  delete open_gl_widget_;
  //  if (data_ptr_ != nullptr) {
  //    free_struct(&data_ptr_);
  //  }
  delete frame_timer_;
  delete stop_timer_;
}

void View::ImportFile() {
  QString file_way = QFileDialog::getOpenFileName(this, "Выбрать файл .obj",
                                                  " ", "Obj files (*.obj)");
  if (!file_way.isEmpty()) {
    try {
      controller_->DataPreparation(file_way.toStdString());
      affine_->CenterCoordinates();
      affine_->ScaleModel(0.5);
      ui_->label_file->clear();
      ui_->label_file->setText("File: " + file_way.split("/").last());
      ui_->label_number_of_vertex->clear();
      ui_->label_number_of_vertex->setText(
          "Number of vertexs: " +
          (QString::number(*(s21::Model::GetInstance()->GetCountOfVertexes()) -
                           1)));
      ui_->label_number_of_facets->clear();
      ui_->label_number_of_facets->setText(
          "Number of facets: " +
          (QString::number(*s21::Model::GetInstance()->GetCountOfFacets())));
      open_gl_widget_->update();
    } catch (std::invalid_argument &e) {
      ui_->label_number_of_facets->clear();
      ui_->label_number_of_vertex->clear();
      ui_->label_number_of_facets->setText("Error: Invalid facet");
    }
  }
}

void View::MoveX(int value) {
  affine_->SetMoveX(value / 100.0);
  open_gl_widget_->update();
}

void View::MoveY(int value) {
  affine_->SetMoveY(value / 100.0);
  open_gl_widget_->update();
}

void View::MoveZ(int value) {
  affine_->SetMoveZ(value / 100.0);
  open_gl_widget_->update();
}

void View::LinesThickness(int value) {
  open_gl_widget_->SetLineThickness((float)value / 10.0f);
  open_gl_widget_->update();
}

void View::VertexesSize(int value) {
  open_gl_widget_->SetVertexSize((float)value);
  open_gl_widget_->update();
}

void View::ProjectionCentral() {
  ui_->scale->setValue(100);
  ui_->move_z->setValue(150);
  ui_->scale->setVisible(false);
  ui_->label_scale->setVisible(false);
  open_gl_widget_->SetTypeProjection(kCentral);
  open_gl_widget_->update();
}
void View::ProjectionOrthogonal() {
  ui_->move_z->setValue(0);
  ui_->scale->setVisible(true);
  ui_->label_scale->setVisible(true);
  open_gl_widget_->SetTypeProjection(kOrthogonal);
  open_gl_widget_->update();
}

void View::LinesSolid() {
  if (*open_gl_widget_->GetTypeLine() != kSolid) {
    open_gl_widget_->SetTypeLine(kSolid);
    open_gl_widget_->update();
  }
}

void View::LinesDashed() {
  if (*open_gl_widget_->GetTypeLine() != kDashed) {
    open_gl_widget_->SetTypeLine(kDashed);
    open_gl_widget_->update();
  }
}

void View::DisplayMethodNone() {
  if (open_gl_widget_->GetTypeVertex() != kNone) {
    open_gl_widget_->SetTypeVertex(kNone);
    open_gl_widget_->update();
  }
}

void View::DisplayMethodCircle() {
  if (open_gl_widget_->GetTypeVertex() != kCircle) {
    open_gl_widget_->SetTypeVertex(kCircle);
    open_gl_widget_->update();
  }
}

void View::DisplayMethodSquare() {
  if (open_gl_widget_->GetTypeVertex() != kSquare) {
    open_gl_widget_->SetTypeVertex(kSquare);
    open_gl_widget_->update();
  }
}
void View::WriteSettings() {
  settings_.setValue("scale", *affine_->GetScale());
  settings_.setValue("rotateX", *affine_->GetRotateX());
  settings_.setValue("rotateY", *affine_->GetRotateY());
  settings_.setValue("rotateZ", *affine_->GetRotateZ());

  settings_.setValue("move_x", *affine_->GetMoveX());
  settings_.setValue("move_y", *affine_->GetMoveY());
  settings_.setValue("move_z", *affine_->GetMoveZ());

  settings_.setValue("line_thickness", ui_->lines_thickness->value());

  settings_.setValue("type_projection", open_gl_widget_->GetTypeProjection());
  settings_.setValue("type_lines", *open_gl_widget_->GetTypeLine());
  settings_.setValue("type_vertex", open_gl_widget_->GetTypeVertex());
  settings_.setValue("vertexes_size", ui_->vertexes_size->value());

  settings_.setValue("color_lines", open_gl_widget_->GetColorLines().name());
  settings_.setValue("color_vertexes",
                     open_gl_widget_->GetColorVertex().name());
  settings_.setValue("color_background",
                     open_gl_widget_->GetColorBackground().name());
}
void View::ReadSettings() {
  open_gl_widget_->SetColorLines(
      QColor(settings_.value("color_lines").toString()));
  open_gl_widget_->SetColorVertex(
      QColor(settings_.value("color_vertexes").toString()));
  open_gl_widget_->SetColorBackground(
      QColor(settings_.value("color_background").toString()));
  open_gl_widget_->SetTypeProjection(
      settings_.value("type_projection").toInt());
  affine_->SetScale(settings_.value("scale").toDouble());

  affine_->SetPrevRotateX(0.0);
  affine_->SetPrevRotateY(0.0);
  affine_->SetPrevRotateZ(0.0);
  ui_->rotate_x->setValue(settings_.value("rotateX").toDouble() /
                          ROTATE_SENSITIVITY);
  ui_->rotate_y->setValue(settings_.value("rotateY").toDouble() /
                          ROTATE_SENSITIVITY);
  ui_->rotate_z->setValue(settings_.value("rotateZ").toDouble() /
                          ROTATE_SENSITIVITY);

  ui_->move_x->setValue(settings_.value("move_x").toDouble() * 100);
  ui_->move_y->setValue(settings_.value("move_y").toDouble() * 100);
  ui_->move_z->setValue(settings_.value("move_z").toDouble() * 100);

  ui_->lines_thickness->setValue(settings_.value("line_thickness").toDouble());

  open_gl_widget_->SetTypeLine(settings_.value("type_lines").toInt());
  open_gl_widget_->SetTypeVertex(settings_.value("type_vertex").toInt());
  if (open_gl_widget_->GetTypeVertex() == kCircle) {
    ui_->radio_display_method_circle->setChecked(true);
  } else if (open_gl_widget_->GetTypeVertex() == kSquare) {
    ui_->radio_display_method_square->setChecked(true);
  } else {
    ui_->radio_display_method_none->setChecked(true);
  }
  if (*open_gl_widget_->GetTypeLine() == kSolid) {
    ui_->radio_lines_solid->setChecked(true);
  } else if (*open_gl_widget_->GetTypeLine() == kDashed) {
    ui_->radio_lines_dashed->setChecked(true);
  }
  if (open_gl_widget_->GetTypeProjection() == kCentral) {
    ui_->radio_projection_central->setChecked(true);
  } else {
    ui_->radio_projection_orthogonal->setChecked(true);
  }
  ui_->vertexes_size->setValue(settings_.value("vertexes_size").toDouble());

  open_gl_widget_->update();
}

void View::ScaleValue(int scale) {
  affine_->SetScale(scale * 1.0 / 100);
  open_gl_widget_->update();
}

void View::ColorBackground() const {
  open_gl_widget_->SetColorBackground(QColorDialog::getColor());
  open_gl_widget_->update();
}

void View::ColorLines() const {
  open_gl_widget_->SetColorLines(QColorDialog::getColor());
  open_gl_widget_->update();
}
void View::ColorVertex() const {
  open_gl_widget_->SetColorVertex(QColorDialog::getColor());
  open_gl_widget_->update();
}

void View::SaveSettings() { WriteSettings(); }

void View::LoadSettings() { ReadSettings(); }

void View::SaveImage() { open_gl_widget_->SaveImage(); }

void View::RotateX(int value) {
  affine_->SetPrevRotateX(*affine_->GetRotateX());
  affine_->SetRotateX((float)value * ROTATE_SENSITIVITY);
  open_gl_widget_->update();
}

void View::RotateY(int value) {
  affine_->SetPrevRotateY(*affine_->GetRotateY());
  affine_->SetRotateY((float)value * ROTATE_SENSITIVITY);
  open_gl_widget_->update();
}

void View::RotateZ(int value) {
  affine_->SetPrevRotateZ(*affine_->GetRotateZ());
  affine_->SetRotateZ((float)value * ROTATE_SENSITIVITY);
  open_gl_widget_->update();
}

void View::StartRecord() {
  connect(frame_timer_, SIGNAL(timeout()), this, SLOT(RecordFrame()));
  frame_timer_->start(100);
  connect(stop_timer_, SIGNAL(timeout()), this, SLOT(StopRecording()));
  stop_timer_->start(5000);
}

void View::RecordFrame() {
  QImage frame = open_gl_widget_->grabFramebuffer();
  frames_.push_back(frame);
}

void View::StopRecording() {
  disconnect(frame_timer_, SIGNAL(timeout()), this, SLOT(RecordFrame()));
  disconnect(stop_timer_, SIGNAL(timeout()), this, SLOT(StopRecording()));
  QString tempFilePath = "animation.gif";
  QString frameListFile = "frameList.txt";
  QFile file(frameListFile);
  if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QTextStream out(&file);
    for (int i = 0; i < frames_.size(); ++i) {
      QString frameFileName = QString("frame_%1.png").arg(i);
      frames_[i].save(frameFileName);
      out << "file '" << frameFileName << "'\n";
    }
    file.close();
  }

  QProcess ffmpegProcess;
  QStringList ffmpegArgs = {
      "-f", "image2", "-framerate", "10", "-i", "frame_%d.png", "-vf",
      "fps=10,scale=640:480:flags=lanczos",  // Устанавливаем FPS и
      // масштабирование (опционально)
      "-y",  // Перезаписать гифку, если она уже существует
      tempFilePath};
  ffmpegProcess.start("ffmpeg", ffmpegArgs);
  ffmpegProcess.waitForFinished(-1);
  // Удаляем временные файлы
  QFile::remove(frameListFile);
  for (int i = 0; i < frames_.size(); ++i) {
    QString frameFileName = QString("frame_%1.png").arg(i);
    QFile::remove(frameFileName);
  }

  // Очищаем список кадров
  frames_.clear();
}

}  // namespace s21
