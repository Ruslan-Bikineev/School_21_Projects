#ifndef VIEW_H_
#define VIEW_H_

#include <string.h>

#include <QList>
#include <QMainWindow>
#include <QVector>

#include "../mvc/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

class View : public QMainWindow {
  Q_OBJECT

 public:
  View(QWidget *parent, s21::Controller *controller);
  ~View();

 private:
  Ui::View *ui_;
  s21::Controller *controller_;

 private slots:
  void ButtonE();
  void Numbers();
  void ButtonAc();
  void Arifmetic();
  void Functions();
  void ButtonDot();
  void ButtonDelete();
  void ButtonUnarny();
  void ButtonGraphic();
  void ButtonCalculate();
  char *InputLineToChar();
  void PlotGraph(QVector<double> *, QVector<double> *);
};

#endif  // VIEW_H_
