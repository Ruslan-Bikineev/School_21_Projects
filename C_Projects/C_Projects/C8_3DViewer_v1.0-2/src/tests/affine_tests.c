#include "tests.h"

START_TEST(test_scale) {
  // Arrange
  uint8_t error = 0;
  DATAPTR data_ptr;
  double scale = 0.5;
  char *file_name = "./tests/files_txt/cube.txt";
  // Act
  viewer_3d(file_name, &error, &data_ptr, &scale);
  double array[][3] = {
      {0.0, 0.0, 0.0},   {1.0, -1.0, -1.0},  {1.0, -1.0, 1.0},
      {-1.0, -1.0, 1.0}, {-1.0, -1.0, -1.0}, {1.0, 1.0, -1.0},
      {1.0, 1.0, 1.0},   {-1.0, 1.0, 1.0},   {-1.0, 1.0, -1.0}};
  for (unsigned i = 1; i < data_ptr->matrix_3d.rows; i++) {
    array[i][X] *= scale;
    array[i][Y] *= scale;
    array[i][Z] *= scale;
  }

  for (unsigned i = 1; i < data_ptr->count_of_vertexes; ++i) {
    ck_assert_double_eq_tol(data_ptr->matrix_3d.matrix[i][X], array[i][X],
                            1e-6);
  }

  free_struct(&data_ptr);
  // Assert
  ck_assert_uint_eq(error, OK);
}
END_TEST

START_TEST(test_move) {
  uint8_t error = 0;
  DATAPTR data_ptr;
  double move = 0.5;
  double scale = 1;
  char *file_name = "./tests/files_txt/cube.txt";
  // Act
  viewer_3d(file_name, &error, &data_ptr, &scale);
  move_model(&data_ptr, move, move, move);
  double array[][3] = {
      {0.0, 0.0, 0.0},   {1.0, -1.0, -1.0},  {1.0, -1.0, 1.0},
      {-1.0, -1.0, 1.0}, {-1.0, -1.0, -1.0}, {1.0, 1.0, -1.0},
      {1.0, 1.0, 1.0},   {-1.0, 1.0, 1.0},   {-1.0, 1.0, -1.0}};
  for (unsigned i = 1; i < data_ptr->matrix_3d.rows; i++) {
    array[i][X] += move;
    array[i][Y] += move;
    array[i][Z] += move;
  }

  for (unsigned i = 1; i < data_ptr->count_of_vertexes; ++i) {
    ck_assert_double_eq_tol(data_ptr->matrix_3d.matrix[i][X], array[i][X],
                            1e-6);
  }

  free_struct(&data_ptr);
  // Assert
  ck_assert_uint_eq(error, OK);
}
END_TEST

START_TEST(test_rotate) {
  uint8_t error = 0;
  DATAPTR data_ptr;
  double angle = 30;
  double scale = 1;
  char *file_name = "./tests/files_txt/cube.txt";
  // Act
  viewer_3d(file_name, &error, &data_ptr, &scale);
  rotate_model(&data_ptr, angle, angle, angle);
  double array[][3] = {
      {0.0, 0.0, 0.0},   {1.0, -1.0, -1.0},  {1.0, -1.0, 1.0},
      {-1.0, -1.0, 1.0}, {-1.0, -1.0, -1.0}, {1.0, 1.0, -1.0},
      {1.0, 1.0, 1.0},   {-1.0, 1.0, 1.0},   {-1.0, 1.0, -1.0}};

  // rotate x
  for (unsigned i = 1; i < data_ptr->matrix_3d.rows; i++) {
    double temp_y = array[i][Y];
    double temp_z = array[i][Z];
    array[i][Y] = cos(angle) * temp_y - sin(angle) * temp_z;
    array[i][Z] = sin(angle) * temp_y + cos(angle) * temp_z;
  }

  // rotate y
  for (unsigned i = 1; i < data_ptr->matrix_3d.rows; i++) {
    double temp_x = array[i][X];
    double temp_z = array[i][Z];
    array[i][X] = cos(angle) * temp_x - sin(angle) * temp_z;
    array[i][Z] = sin(angle) * temp_x + cos(angle) * temp_z;
  }

  // rotate z
  for (unsigned i = 1; i < data_ptr->matrix_3d.rows; i++) {
    double temp_x = array[i][X];
    double temp_y = array[i][Y];
    array[i][X] = cos(angle) * temp_x - sin(angle) * temp_y;
    array[i][Y] = sin(angle) * temp_x + cos(angle) * temp_y;
  }

  for (unsigned i = 1; i < data_ptr->count_of_vertexes; ++i) {
    ck_assert_double_eq_tol(array[i][X], array[i][X], 1e-6);
  }

  free_struct(&data_ptr);
  // Assert
  ck_assert_uint_eq(error, OK);
}
END_TEST

Suite *affine_tests() {
  Suite *suite = suite_create("Affine");
  TCase *tc = tcase_create("Affine");
  tcase_add_test(tc, test_scale);
  tcase_add_test(tc, test_move);
  tcase_add_test(tc, test_rotate);
  suite_add_tcase(suite, tc);

  return suite;
}
