#include <QApplication>

#include "view.h"

int main(int argc, char *argv[]) {
  s21::Model model;
  s21::Controller controller(&model);
  QApplication a(argc, argv);
  View *w = new View(nullptr, &controller);
  w->setWindowTitle("Smart Calculator v2.0");
  // Убираем кнопку "Максимизировать"
  w->setWindowFlags(w->windowFlags() & ~Qt::WindowMaximizeButtonHint);
  w->show();
  return a.exec();
}
