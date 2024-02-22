#include "tests.h"

START_TEST(success_parsing_positive_file) {
  // Arrange
  uint8_t error = 0;
  double scale = 1.0;
  DATAPTR data_ptr = NULL;
  char *file_name = "./tests/files_txt/cube.txt";
  const unsigned count_of_vertexes = 9;
  const unsigned count_of_facets = 12;
  const double matrix[][3] = {
      {0.0, 0.0, 0.0},   {1.0, -1.0, -1.0},  {1.0, -1.0, 1.0},
      {-1.0, -1.0, 1.0}, {-1.0, -1.0, -1.0}, {1.0, 1.0, -1.0},
      {1.0, 1.0, 1.0},   {-1.0, 1.0, 1.0},   {-1.0, 1.0, -1.0}};
  const int polygon[][3] = {{2, 3, 4}, {8, 7, 6}, {5, 6, 2}, {6, 7, 3},
                            {3, 7, 8}, {1, 4, 8}, {1, 2, 4}, {5, 8, 6},
                            {1, 5, 2}, {2, 6, 3}, {4, 3, 8}, {5, 1, 8}};
  // Act
  viewer_3d(file_name, &error, &data_ptr, &scale);
  // Assert
  ck_assert_uint_eq(count_of_vertexes, data_ptr->count_of_vertexes);
  ck_assert_uint_eq(count_of_facets, data_ptr->count_of_facets);
  for (unsigned i = 1; i < count_of_vertexes; i++) {
    for (unsigned j = 0; j < 3; j++) {
      ck_assert_double_eq(data_ptr->matrix_3d.matrix[i][j], matrix[i][j]);
    }
  }
  for (unsigned i = 0; i < count_of_facets; i++) {
    for (unsigned j = 0; j < 3; j++) {
      ck_assert_int_eq(data_ptr->polygons[i].vertexes[j], polygon[i][j]);
    }
  }
  ck_assert_uint_eq(error, OK);
  free_struct(&data_ptr);
}
END_TEST

START_TEST(success_parsing_negative_file) {
  // Arrange
  uint8_t error = 0;
  double scale = 0.5;
  DATAPTR data_ptr = NULL;
  char *file_name = "./tests/files_txt/cube_neg.txt";
  const unsigned count_of_vertexes = 9;
  const unsigned count_of_facets = 2;
  const double matrix[][3] = {
      {0.0, 0.0, 0.0},    {0.5, 0.5, -0.5},  {0.5, -0.5, -0.5},
      {-0.5, -0.5, -0.5}, {-0.5, 0.5, -0.5}, {-0.5, -0.5, 0.5},
      {-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5}, {0.5, -0.5, 0.5}};
  const int polygon[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
  // Act
  viewer_3d(file_name, &error, &data_ptr, &scale);
  // Assert
  ck_assert_uint_eq(count_of_vertexes, data_ptr->count_of_vertexes);
  ck_assert_uint_eq(count_of_facets, data_ptr->count_of_facets);
  for (unsigned i = 1; i < count_of_vertexes; i++) {
    for (unsigned j = 0; j < 3; j++) {
      ck_assert_double_eq(data_ptr->matrix_3d.matrix[i][j], matrix[i][j]);
    }
  }
  for (unsigned i = 0; i < count_of_facets; i++) {
    for (unsigned j = 0; j < 4; j++) {
      ck_assert_int_eq(data_ptr->polygons[i].vertexes[j], polygon[i][j]);
    }
  }
  ck_assert_uint_eq(error, OK);
  free_struct(&data_ptr);
}
END_TEST

START_TEST(no_file_for_parser) {
  // Arrange
  uint8_t error = 0;
  DATAPTR data_ptr = NULL;
  double scale = 1.0;
  char *file_name = "./tests/files_txt/cube.tx";
  // Act
  viewer_3d(file_name, &error, &data_ptr, &scale);
  free_struct(&data_ptr);
  // Assert
  ck_assert_uint_eq(error, FILE_FAIL);
}
END_TEST

START_TEST(inccorrect_vertex) {
  // Arrange
  uint8_t error = 0;
  DATAPTR data_ptr = NULL;
  double scale = 1.0;
  char *file_name = "./tests/files_txt/fail1_cube.txt";
  // Act
  viewer_3d(file_name, &error, &data_ptr, &scale);
  free_struct(&data_ptr);
  // Assert
  ck_assert_uint_eq(error, VERTEX_IN_FAIL);
}
END_TEST

START_TEST(the_number_of_polygons_exceeding_the_number_of_vertices) {
  // Arrange
  uint8_t error = 0;
  DATAPTR data_ptr = NULL;
  double scale = 1.0;
  char *file_name = "./tests/files_txt/fail2_cube.txt";
  // Act
  viewer_3d(file_name, &error, &data_ptr, &scale);
  free_struct(&data_ptr);
  // Assert
  ck_assert_uint_eq(error, FILE_FAIL);
}
END_TEST

START_TEST(inccorrect_polygon) {
  // Arrange
  uint8_t error = 0;
  DATAPTR data_ptr = NULL;
  double scale = 1.0;
  char *file_name = "./tests/files_txt/fail3_cube.txt";
  // Act
  viewer_3d(file_name, &error, &data_ptr, &scale);
  free_struct(&data_ptr);
  // Assert
  ck_assert_uint_eq(error, POLYGON_IN_FAIL);
}
END_TEST

Suite *parser_tests(void) {
  Suite *s = suite_create("Parser tests");

  TCase *parser_tests = tcase_create("3D Viewer_v1.0 ");
  tcase_add_test(parser_tests, success_parsing_positive_file);
  tcase_add_test(parser_tests, success_parsing_negative_file);
  tcase_add_test(parser_tests, no_file_for_parser);
  tcase_add_test(parser_tests, inccorrect_vertex);
  tcase_add_test(parser_tests,
                 the_number_of_polygons_exceeding_the_number_of_vertices);
  tcase_add_test(parser_tests, inccorrect_polygon);

  suite_add_tcase(s, parser_tests);

  return s;
}