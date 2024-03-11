#include <QApplication>

#include "view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Model *model = s21::Model::GetInstance();
  s21::Controller controller(model);
  s21::View view(nullptr, &controller);
  view.setWindowTitle("3DViewer v2.0");
  // Убираем кнопку "Максимизировать"
  view.setWindowFlags(view.windowFlags() & ~Qt::WindowMaximizeButtonHint);
  view.setWindowState(Qt::WindowMaximized);
  view.show();
  return a.exec();
}
