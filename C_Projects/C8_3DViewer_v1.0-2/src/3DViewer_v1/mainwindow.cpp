#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  data_ptr = nullptr;
  QCoreApplication::setOrganizationName("Dream team");
  QCoreApplication::setApplicationName("3DViewer_v1.0");
  openGLWidget = new OpenGLWidget(ui->widgetGl, &data_ptr);
  ui->widgetGl->setLayout(new QVBoxLayout());
  ui->widgetGl->layout()->addWidget(openGLWidget);
  frame_timer = new QTimer(this);
  stop_timer = new QTimer(this);
}

MainWindow::~MainWindow() {
  delete ui;
  if (data_ptr != nullptr) {
    free_struct(&data_ptr);
  }
  delete frame_timer;
  delete stop_timer;
}

void MainWindow::on_button_import_file_clicked() {
  uint8_t error = 0;
  QString file_way = QFileDialog::getOpenFileName(this, "Выбрать файл .obj",
                                                  " ", "Obj files (*.obj)");
  if (!file_way.isEmpty()) {
    QByteArray file_way_ba = file_way.toUtf8();
    char *file_way_ptr = file_way_ba.data();
    double scale = 0.5;
    if (data_ptr != nullptr) {
      free_struct(&data_ptr);
    }
    viewer_3d(file_way_ptr, &error, &data_ptr, &scale);
    ui->label_file->clear();
    ui->label_file->setText("File: " + file_way.split("/").last());
    if (error != OK) {
      ui->label_number_of_facets->clear();
      ui->label_number_of_vertex->clear();
      ui->label_number_of_facets->setText("Error: " +
                                          (description_error(&error)));
    } else {
      ui->label_number_of_vertex->clear();
      ui->label_number_of_vertex->setText(
          "Number of vertexs: " +
          (QString::number(data_ptr->count_of_vertexes - 1)));
      ui->label_number_of_facets->clear();
      ui->label_number_of_facets->setText(
          "Number of facets: " + (QString::number(data_ptr->count_of_facets)));
      openGLWidget->update();
    }
  }
}

void MainWindow::on_move_x_valueChanged(int value) {
  openGLWidget->move_x = value / 100.0;
  openGLWidget->update();
}

void MainWindow::on_move_y_valueChanged(int value) {
  openGLWidget->move_y = value / 100.0;
  openGLWidget->update();
}

void MainWindow::on_move_z_valueChanged(int value) {
  openGLWidget->move_z = value / 100.0;
  openGLWidget->update();
}
void MainWindow::on_color_backgroung_R_valueChanged(int value) {
  openGLWidget->color_background[R] = (float)value;
  openGLWidget->update();
}

void MainWindow::on_color_backgroung_G_valueChanged(int value) {
  openGLWidget->color_background[G] = (float)value;
  openGLWidget->update();
}

void MainWindow::on_color_backgroung_B_valueChanged(int value) {
  openGLWidget->color_background[B] = (float)value;
  openGLWidget->update();
}

void MainWindow::on_color_lines_R_valueChanged(int value) {
  openGLWidget->color_lines[R] = (float)value;
  openGLWidget->update();
}

void MainWindow::on_color_lines_G_valueChanged(int value) {
  openGLWidget->color_lines[G] = (float)value;
  openGLWidget->update();
}

void MainWindow::on_color_lines_B_valueChanged(int value) {
  openGLWidget->color_lines[B] = (float)value;
  openGLWidget->update();
}

void MainWindow::on_lines_thickness_valueChanged(int value) {
  openGLWidget->line_thickness = (float)value / 10.0f;
  openGLWidget->update();
}

void MainWindow::on_vertexes_size_valueChanged(int value) {
  openGLWidget->vertex_size = (float)value;
  openGLWidget->update();
}

void MainWindow::on_color_vertex_R_valueChanged(int value) {
  openGLWidget->color_vertex[R] = (float)value;
  openGLWidget->update();
}

void MainWindow::on_color_vertex_G_valueChanged(int value) {
  openGLWidget->color_vertex[G] = (float)value;
  openGLWidget->update();
}

void MainWindow::on_color_vertex_B_valueChanged(int value) {
  openGLWidget->color_vertex[B] = (float)value;
  openGLWidget->update();
}

void MainWindow::on_radio_projection_central_clicked() {
  //  if (openGLWidget->type_projection != CENTRAL) {
  openGLWidget->type_projection = CENTRAL;
  openGLWidget->change_projection();
  openGLWidget->update();
  //  }
}
void MainWindow::on_radio_projection_orthogonal_clicked() {
  //  if (openGLWidget->type_projection != ORTHOGONAL) {
  openGLWidget->type_projection = ORTHOGONAL;
  openGLWidget->change_projection();
  openGLWidget->update();
  //  }
}

void MainWindow::on_radio_lines_solid_clicked() {
  if (openGLWidget->type_lines != SOLID) {
    openGLWidget->type_lines = SOLID;
    openGLWidget->update();
  }
}

void MainWindow::on_radio_lines_dashed_clicked() {
  if (openGLWidget->type_lines != DASHED) {
    openGLWidget->type_lines = DASHED;
    openGLWidget->update();
  }
}

void MainWindow::on_radio_display_method_none_clicked() {
  if (openGLWidget->type_vertex != NONE) {
    openGLWidget->type_vertex = NONE;
    openGLWidget->update();
  }
}

void MainWindow::on_radio_display_method_circle_clicked() {
  if (openGLWidget->type_vertex != CIRCLE) {
    openGLWidget->type_vertex = CIRCLE;
    openGLWidget->update();
  }
}

void MainWindow::on_radio_display_method_square_clicked() {
  if (openGLWidget->type_vertex != SQUARE) {
    openGLWidget->type_vertex = SQUARE;
    openGLWidget->update();
  }
}
void MainWindow::write_settings() {
  settings.setValue("scale", openGLWidget->scale);
  settings.setValue("rotateX", openGLWidget->rotateX);
  settings.setValue("rotateY", openGLWidget->rotateY);
  settings.setValue("rotateZ", openGLWidget->rotateZ);

  settings.setValue("move_x", openGLWidget->move_x);
  settings.setValue("move_y", openGLWidget->move_y);
  settings.setValue("move_z", openGLWidget->move_z);

  settings.setValue("color_background_R", ui->color_backgroung_R->value());
  settings.setValue("color_background_G", ui->color_backgroung_G->value());
  settings.setValue("color_background_B", ui->color_backgroung_B->value());
  settings.setValue("color_lines_R", ui->color_lines_R->value());
  settings.setValue("color_lines_G", ui->color_lines_G->value());
  settings.setValue("color_lines_B", ui->color_lines_B->value());
  settings.setValue("color_vertex_R", ui->color_vertex_R->value());
  settings.setValue("color_vertex_G", ui->color_vertex_G->value());
  settings.setValue("color_vertex_B", ui->color_vertex_B->value());
  settings.setValue("line_thickness", ui->lines_thickness->value());

  settings.setValue("type_projection", openGLWidget->type_projection);
  settings.setValue("type_lines", openGLWidget->type_lines);
  settings.setValue("type_vertex", openGLWidget->type_vertex);
  settings.setValue("vertexes_size", ui->vertexes_size->value());
}
void MainWindow::read_settings() {
  openGLWidget->type_projection = settings.value("type_projection").toInt();
  openGLWidget->scale = settings.value("scale").toDouble();

  openGLWidget->prev_rotateX = 0.0;
  openGLWidget->prev_rotateY = 0.0;
  openGLWidget->prev_rotateZ = 0.0;
  ui->rotate_x->setValue(settings.value("rotateX").toDouble() /
                         ROTATE_SENSITIVITY);
  ui->rotate_y->setValue(settings.value("rotateY").toDouble() /
                         ROTATE_SENSITIVITY);
  ui->rotate_z->setValue(settings.value("rotateZ").toDouble() /
                         ROTATE_SENSITIVITY);

  ui->color_backgroung_R->setValue(
      settings.value("color_background_R").toDouble());
  ui->color_backgroung_G->setValue(
      settings.value("color_background_G").toDouble());
  ui->color_backgroung_B->setValue(
      settings.value("color_background_B").toDouble());

  ui->move_z->setValue((int)settings.value("move_z").toDouble() * 100);
  ui->move_y->setValue(settings.value("move_y").toDouble() * 100);
  ui->move_x->setValue(settings.value("move_x").toDouble() * 100);

  ui->color_lines_R->setValue(settings.value("color_lines_R").toDouble());
  ui->color_lines_G->setValue(settings.value("color_lines_G").toDouble());
  ui->color_lines_B->setValue(settings.value("color_lines_B").toDouble());
  ui->color_vertex_R->setValue(settings.value("color_vertex_R").toDouble());
  ui->color_vertex_G->setValue(settings.value("color_vertex_G").toDouble());
  ui->color_vertex_B->setValue(settings.value("color_vertex_B").toDouble());
  ui->lines_thickness->setValue(settings.value("line_thickness").toDouble());

  openGLWidget->type_lines = settings.value("type_lines").toInt();
  openGLWidget->type_vertex = settings.value("type_vertex").toInt();
  if (openGLWidget->type_vertex == CIRCLE) {
    ui->radio_display_method_circle->setChecked(true);
  } else if (openGLWidget->type_vertex == SQUARE) {
    ui->radio_display_method_square->setChecked(true);
  } else {
    ui->radio_display_method_none->setChecked(true);
  }
  if (openGLWidget->type_lines == SOLID) {
    ui->radio_lines_solid->setChecked(true);
  } else if (openGLWidget->type_lines == DASHED) {
    ui->radio_lines_dashed->setChecked(true);
  }
  if (openGLWidget->type_projection == CENTRAL) {
    ui->radio_projection_central->setChecked(true);
  } else {
    ui->radio_projection_orthogonal->setChecked(true);
  }
  ui->vertexes_size->setValue(settings.value("vertexes_size").toDouble());

  openGLWidget->update();
}

void MainWindow::on_save_button_clicked() { write_settings(); }

void MainWindow::on_load_button_clicked() { read_settings(); }

void MainWindow::on_button_save_as_image_clicked() {
  openGLWidget->save_image();
}

void MainWindow::on_rotate_x_valueChanged(int value) {
  openGLWidget->prev_rotateX = openGLWidget->rotateX;
  openGLWidget->rotateX = (float)value * ROTATE_SENSITIVITY;
  openGLWidget->update();
}

void MainWindow::on_rotate_y_valueChanged(int value) {
  openGLWidget->prev_rotateY = openGLWidget->rotateY;
  openGLWidget->rotateY = (float)value * ROTATE_SENSITIVITY;
  openGLWidget->update();
}

void MainWindow::on_rotate_z_valueChanged(int value) {
  openGLWidget->prev_rotateZ = openGLWidget->rotateZ;
  openGLWidget->rotateZ = (float)value * ROTATE_SENSITIVITY;
  openGLWidget->update();
}

void MainWindow::on_record_button_clicked() {
  connect(frame_timer, SIGNAL(timeout()), this, SLOT(record_frame()));
  frame_timer->start(100);
  connect(stop_timer, SIGNAL(timeout()), this, SLOT(stop_recording()));
  stop_timer->start(5000);
}

void MainWindow::record_frame() {
  QImage frame = openGLWidget->grabFramebuffer();
  frames.push_back(frame);
}

QString MainWindow::description_error(uint8_t *error) {
  QString messseng = "Error!";
  if (*error == 2) {
    messseng = "Memory allocation error!";
  } else if (*error == 3) {
    messseng = "Incorrect file!";
  } else if (*error == 4) {
    messseng = "Regex compilation fail!";
  } else if (*error == 5) {
    messseng = "Incorrect vertex in file!";
  } else if (*error == 6) {
    messseng = "Incorrect polygon in file!";
  }
  return messseng;
}

void MainWindow::stop_recording() {
  disconnect(frame_timer, SIGNAL(timeout()), this, SLOT(record_frame()));
  disconnect(stop_timer, SIGNAL(timeout()), this, SLOT(stop_recording()));
  QString tempFilePath = "animation.gif";
  QString frameListFile = "frameList.txt";
  QFile file(frameListFile);
  if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QTextStream out(&file);
    for (int i = 0; i < frames.size(); ++i) {
      QString frameFileName = QString("frame_%1.png").arg(i);
      frames[i].save(frameFileName);
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
  for (int i = 0; i < frames.size(); ++i) {
    QString frameFileName = QString("frame_%1.png").arg(i);
    QFile::remove(frameFileName);
  }

  // Очищаем список кадров
  frames.clear();
}
