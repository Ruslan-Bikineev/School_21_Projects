#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string.h>

#include <QMainWindow>
#include <QVector>
extern "C" {
#include "../Backend/smart_calc_v1.0.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  QString _stringCalculate;

 private slots:
  void digits_numbers();
  void button_ac_click();
  void button_delete_click();
  void on_pushButton_dot_clicked();
  void arifmetic_operations();
  void functions();
  void on_pushButton_unarny_clicked();
  void on_pushButton_calculate_clicked();
  void on_pushButton_graphic_clicked();
};

#endif  // MAINWINDOW_H
