#ifndef CPP4_3DVIEWER_V2_0_1_SRC_3DVIEWER_VIEW_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_3DVIEWER_VIEW_H_
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif
#include <QColorDialog>
#include <QFileDialog>
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

#include "../Backend/affine_facade.h"
#include "../Backend/controller.h"
#include "OpenGLWidget.h"
#define ROTATE_SENSITIVITY 0.01

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE
namespace s21 {
class OpenGLWidget;

class View : public QMainWindow {
  Q_OBJECT

 public:
  explicit View(QWidget *parent, s21::Controller *controller);
  ~View() override;
  OpenGLWidget *open_gl_widget_;
 private slots:
  void MoveX(int);
  void MoveY(int);
  void MoveZ(int);
  void SaveImage();
  void ImportFile();
  void RotateX(int);
  void RotateY(int);
  void RotateZ(int);
  void LinesSolid();
  void RecordFrame();
  void StartRecord();
  void LinesDashed();
  void SaveSettings();
  void LoadSettings();
  void StopRecording();
  void ScaleValue(int);
  void VertexesSize(int);
  void ColorLines() const;
  void LinesThickness(int);
  void ProjectionCentral();
  void DisplayMethodNone();
  void ColorVertex() const;
  void DisplayMethodCircle();
  void DisplayMethodSquare();
  void ProjectionOrthogonal();
  void ColorBackground() const;

 private:
  Ui::View *ui_;
  void ReadSettings();
  QSettings settings_;
  QTimer *stop_timer_;
  QTimer *frame_timer_;
  void WriteSettings();
  QVector<QImage> frames_;
  s21::Controller *controller_;
  AffineFacade *affine_ = new AffineFacade();
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_3DVIEWER_VIEW_H_
