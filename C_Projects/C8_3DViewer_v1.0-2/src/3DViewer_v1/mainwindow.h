#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif
//#include "GL/glu.h"
#include <QMainWindow>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QProcess>
#include <QPushButton>
#include <QSettings>
#include <QTimer>
#include <QVBoxLayout>
#include <QVector>

#include "OpenGLWidget.h"
extern "C" {
#include "../Backend/general.h"
}
#include <QFileDialog>
#define ROTATE_SENSITIVITY 0.01

class OpenGLWidget;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override;
  OpenGLWidget *openGLWidget;
 private slots:
  void on_button_import_file_clicked();

  void on_move_x_valueChanged(int value);

  void on_move_y_valueChanged(int value);

  void on_move_z_valueChanged(int value);

  void on_color_backgroung_R_valueChanged(int value);

  void on_color_backgroung_G_valueChanged(int value);

  void on_color_backgroung_B_valueChanged(int value);

  void on_color_lines_R_valueChanged(int value);

  void on_color_lines_G_valueChanged(int value);

  void on_color_lines_B_valueChanged(int value);

  void on_lines_thickness_valueChanged(int value);

  void on_radio_projection_central_clicked();

  void on_radio_projection_orthogonal_clicked();

  void on_radio_lines_solid_clicked();

  void on_radio_lines_dashed_clicked();

  void on_radio_display_method_none_clicked();

  void on_radio_display_method_circle_clicked();

  void on_radio_display_method_square_clicked();

  void on_vertexes_size_valueChanged(int value);

  void on_color_vertex_R_valueChanged(int value);

  void on_color_vertex_G_valueChanged(int value);

  void on_color_vertex_B_valueChanged(int value);

  void on_save_button_clicked();

  void on_load_button_clicked();

  void on_button_save_as_image_clicked();

  void on_rotate_x_valueChanged(int value);

  void on_rotate_y_valueChanged(int value);

  void on_rotate_z_valueChanged(int value);

  void on_record_button_clicked();

  void stop_recording();

  void record_frame();

  QString description_error(uint8_t *error);

 private:
  DATAPTR data_ptr;
  Ui::MainWindow *ui;
  QSettings settings;
  QTimer *frame_timer;
  QTimer *stop_timer;
  QVector<QImage> frames;
  void write_settings();
  void read_settings();
};
#endif  // MAINWINDOW_H
