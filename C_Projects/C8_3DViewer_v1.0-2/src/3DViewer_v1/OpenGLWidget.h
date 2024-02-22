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
extern "C" {
#include "../Backend/general.h"
}
#ifndef C8_3DVIEWER_V1_0_1_OPENGLWINDOW_H
#define C8_3DVIEWER_V1_0_1_OPENGLWINDOW_H

class OpenGLWidget : public QOpenGLWidget {
  Q_OBJECT
 public:
  OpenGLWidget(QWidget *parent = nullptr, DATAPTR *data_ptr = nullptr);
  ~OpenGLWidget();
  void affine();
  void create_vertexes();
  void change_projection();
  void save_image();
  void draw_vertexes();
  void update_prev_values();
  void create_poligons(unsigned *);
  void print_error();
  GLfloat *vertexArray;
  GLuint *indexArray;
  GLenum error;
  double scale;
  double move_x;
  double move_y;
  double move_z;
  double rotateX;
  double rotateY;
  double rotateZ;
  float color_background[3] = {0, 0, 0};
  float color_lines[3] = {255, 255, 255};
  float color_vertex[3] = {155, 155, 155};
  float line_thickness = 1;  // or line width
  float vertex_size = 10;    // or line width
  unsigned type_projection = ORTHOGONAL;
  unsigned prev_type_projection = ORTHOGONAL;
  unsigned type_lines = SOLID;
  unsigned type_vertex = NONE;
  double prev_rotateX;
  double prev_rotateY;
  double prev_rotateZ;
  double prev_scale;
  double prev_move_x;
  double prev_move_y;
  double prev_move_z;

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void wheelEvent(QWheelEvent *event) override;

 private:
  DATAPTR *data_ptr;
  int lastMouseX;
  int lastMouseY;
};

#endif  // C8_3DVIEWER_V1_0_1_OPENGLWINDOW_H