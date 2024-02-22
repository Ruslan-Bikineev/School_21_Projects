#include "OpenGLWidget.h"

//#include <time.h>

//#include <QDebug>
#include <QFileDialog>

OpenGLWidget::OpenGLWidget(QWidget *parent, DATAPTR *data_ptr)
    : QOpenGLWidget(parent), data_ptr(data_ptr) {
  scale = 1;
  move_x = 0;
  move_y = 0;
  move_z = 0;
  rotateX = 0;
  rotateY = 0;
  rotateZ = 0;
  prev_scale = 0;
  prev_move_x = 0;
  prev_move_y = 0;
  prev_move_z = 0;
  prev_rotateX = 0;
  prev_rotateY = 0;
  prev_rotateZ = 0;
}

void OpenGLWidget::paintGL() {
  if (data_ptr != nullptr && *data_ptr != nullptr) {
    //    clock_t start, end;
    //    start = clock();
    //    double execution_time;
    change_projection();
    glClearColor(color_background[R] / 255.0, color_background[G] / 255.0,
                 color_background[B] / 255.0, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    //        glMatrixMode(GL_PROJECTION);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glEnableClientState(GL_VERTEX_ARRAY);
    affine();
    glLineWidth(line_thickness);
    vertexArray = new GLfloat[(*data_ptr)->count_of_vertexes * 3];
    create_vertexes();
    glVertexPointer(3, GL_FLOAT, 0, vertexArray);
    draw_vertexes();
    // Create an index array for glDrawElements
    indexArray = new GLuint[(*data_ptr)->count_of_facets *
                            (*data_ptr)->polygons[0].number_of_facets * 3];
    unsigned currentIndex = 0;
    create_poligons(&currentIndex);
    glLineWidth(line_thickness);
    glColor3f(color_lines[R] / 255.0f, color_lines[G] / 255.0f,
              color_lines[B] / 255.0f);  // color of lines
    if (type_lines == DASHED) {
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(1, 0x3333);  // Set line stipple pattern
    } else {
      glDisable(GL_LINE_STIPPLE);
    }
    glDrawElements(GL_LINES, currentIndex, GL_UNSIGNED_INT, indexArray);
    glDisableClientState(GL_VERTEX_ARRAY);
    print_error();
    delete[] vertexArray;
    delete[] indexArray;
    //    end = clock();
    //    execution_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    //    printf("OpenGL execution time: %f\n", execution_time);
    update_prev_values();
  }
}

void OpenGLWidget::create_poligons(unsigned *currentIndex) {
  for (unsigned i = 0; i < (*data_ptr)->count_of_facets; ++i) {
    for (int j = 0; j < (*data_ptr)->polygons[i].number_of_facets - 1; ++j) {
      indexArray[(*currentIndex)++] = (*data_ptr)->polygons[i].vertexes[j];
      indexArray[(*currentIndex)++] = (*data_ptr)->polygons[i].vertexes[j + 1];
    }
    // Connect the last and first vertices to close the loop
    indexArray[(*currentIndex)++] =
        (*data_ptr)
            ->polygons[i]
            .vertexes[(*data_ptr)->polygons[i].number_of_facets - 1];
    indexArray[(*currentIndex)++] = (*data_ptr)->polygons[i].vertexes[0];
  }
}
void OpenGLWidget::print_error() {
  error = glGetError();
  if (error != GL_NO_ERROR) {
    printf("OpenGL error: %d\n", error);
  }
}
void OpenGLWidget::initializeGL() { QOpenGLWidget::initializeGL(); }

void OpenGLWidget::resizeGL(int w, int h) { QOpenGLWidget::resizeGL(w, h); }

OpenGLWidget::~OpenGLWidget() {}

void OpenGLWidget::affine() {
  if (prev_scale != scale) {
    scale_model(data_ptr, &scale);
  }
  if (prev_move_x != move_x || prev_move_y != move_y || prev_move_z != move_z) {
    move_model(data_ptr, move_x - prev_move_x, prev_move_y - move_y,
               prev_move_z - move_z);
  }
  if (prev_rotateX != rotateX || prev_rotateY != rotateY ||
      prev_rotateZ != rotateZ) {
    rotate_model(data_ptr, rotateX - prev_rotateX, rotateY - prev_rotateY,
                 rotateZ - prev_rotateZ);
  }
}

void OpenGLWidget::wheelEvent(QWheelEvent *event) {
  const double scaleSensitivity = 0.1;
  if (scale < 5.0 && scale > 0.2) {
    scale += scaleSensitivity * event->angleDelta().y() / 120.0;

  } else {
    if (scale >= 5) {
      scale -= 0.1;
    } else {
      scale += 0.1;
    }
  }
  update();
}

void OpenGLWidget::change_projection() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (type_projection == CENTRAL) {
    //    gluPerspective(60, 1.0, 1.0, 100.0);
    float fov = 60.0 * M_PI / 180;
    float heapHeight = 1 / (2 * tan(fov / 2));
    glFrustum(-1, 1, -1, 1, heapHeight, 99999);
    if (prev_type_projection == ORTHOGONAL) {
      centering_coordinates(data_ptr);
      move_model(data_ptr, 0, 0, -heapHeight * 3);
    }
  } else if (type_projection == ORTHOGONAL) {
    if (prev_type_projection == CENTRAL) {
      centering_coordinates(data_ptr);
    }
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 99999);
  }
  prev_type_projection = type_projection;
}

void OpenGLWidget::save_image() {
  QImage image = this->grabFramebuffer();
  QString selectedFilter;
  QString file_name = QFileDialog::getSaveFileName(
      this, "Save image", " ", ".bmp;;.jpeg", &selectedFilter);
  if (!file_name.isEmpty()) {
    image.save(file_name.remove(" ") + selectedFilter);
  }
}

void OpenGLWidget::create_vertexes() {
  vertexArray[0] = 0;
  vertexArray[1] = 0;
  vertexArray[2] = 0;
  for (unsigned i = 1; i < (*data_ptr)->count_of_vertexes; ++i) {
    vertexArray[i * 3 + X] =
        static_cast<GLfloat>((*data_ptr)->matrix_3d.matrix[i][X]);
    vertexArray[i * 3 + Y] =
        static_cast<GLfloat>((*data_ptr)->matrix_3d.matrix[i][Y]);
    vertexArray[i * 3 + Z] =
        static_cast<GLfloat>((*data_ptr)->matrix_3d.matrix[i][Z]);
  }
}

void OpenGLWidget::draw_vertexes() {
  if (type_vertex != NONE) {
    glPointSize(vertex_size);
    glColor3f(color_vertex[R] / 255.0f, color_vertex[G] / 255.0f,
              color_vertex[B] / 255.0f);  // color of points
    if (type_vertex == CIRCLE) {  // smooth point, default is square. On my
                                  // notebook it doesn't work
      glEnable(GL_POINT_SMOOTH);
      glDrawArrays(GL_POINTS, 1, (*data_ptr)->count_of_vertexes - 1);
      glDisable(GL_POINT_SMOOTH);
    } else {
      glDrawArrays(GL_POINTS, 1, (*data_ptr)->count_of_vertexes - 1);
    }
  }
}

void OpenGLWidget::update_prev_values() {
  prev_move_x = move_x;
  prev_move_y = move_y;
  prev_move_z = move_z;
  prev_rotateX = rotateX;
  prev_rotateY = rotateY;
  prev_rotateZ = rotateZ;
  prev_scale = scale;
}
