#ifndef CPP4_3DVIEWER_V2_0_1_SRC_3DVIEWER_OPENGLWIDGET_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_3DVIEWER_OPENGLWIDGET_H_

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif
#include <QImage>
#include <QMainWindow>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include "../Backend/affine_facade.h"
#include "../Backend/model.h"
#include "../Backend/move_coordinates_context.h"
#include "../Backend/rotate_coordinates_context.h"

namespace s21 {
class OpenGLWidget : public QOpenGLWidget {
  Q_OBJECT
 public:
  explicit OpenGLWidget(QWidget *parent = nullptr,
                        AffineFacade *affine = nullptr);
  ~OpenGLWidget() override;
  void SaveImage();
  void DrawVertexes();
  void CreatePolygons();
  void ChangeProjection();
  const unsigned *GetTypeLine() { return &type_line_; }
  void SetTypeLine(const unsigned type_line) { type_line_ = type_line; }
  void SetTypeVertex(unsigned int type_vertex) { type_vertex_ = type_vertex; }
  void SetTypeProjection(unsigned int type_projection) {
    type_projection_ = type_projection;
  }
  void SetColorBackground(const QColor &color_background) {
    color_background_ = color_background;
  }
  void SetColorLines(const QColor &color_lines) { color_lines_ = color_lines; }
  void SetLineThickness(float line_thickness) {
    line_thickness_ = line_thickness;
  }
  void SetVertexSize(float vertex_size) { vertex_size_ = vertex_size; }
  void SetColorVertex(const QColor &color_vertex) {
    color_vertex_ = color_vertex;
  }
  unsigned int GetTypeVertex() const { return type_vertex_; }
  unsigned int GetTypeProjection() const { return type_projection_; }
  const QColor &GetColorBackground() const { return color_background_; }
  const QColor &GetColorLines() const { return color_lines_; }
  const QColor &GetColorVertex() const { return color_vertex_; }

 protected:
  void paintGL() override;
  void initializeGL() override;
  void resizeGL(int w, int h) override;

 private:
  std::vector<GLuint> *index_array_;
  unsigned type_line_;
  AffineFacade *affine_;
  Model *model_;
  unsigned type_vertex_;
  unsigned type_projection_;
  QColor color_background_;
  QColor color_lines_;
  float line_thickness_;
  unsigned prev_type_projection_;
  float vertex_size_;
  QColor color_vertex_;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_3DVIEWER_OPENGLWIDGET_H_
