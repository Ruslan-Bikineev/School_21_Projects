#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  // Убираем кнопку "Максимизировать"
  w.setWindowFlags(w.windowFlags() & ~Qt::WindowMaximizeButtonHint);
  w.setWindowState(Qt::WindowMaximized);
  w.show();
  return a.exec();
}
