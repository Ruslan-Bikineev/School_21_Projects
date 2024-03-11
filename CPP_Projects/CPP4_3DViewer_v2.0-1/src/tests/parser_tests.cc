#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "../Backend/model.h"

class ParserTest : public testing::Test {
 protected:
  void SetUp() {
    std::vector<double> buffer_vertexes_1{
        1.0, -1.0, -1.0, 1.0, -1.0, 1.0, -1.0, -1.0, 1.0, -1.0, -1.0, -1.0,
        1.0, 1.0,  -1.0, 1.0, 1.0,  1.0, -1.0, 1.0,  1.0, -1.0, 1.0,  -1.0};
    for (double &i : buffer_vertexes_1) {
      expected_1.AddCoordinate(i);
    }
    std::vector<int> vector_1_1{2, 3, 4};
    std::vector<int> vector_1_2{8, 7, 6};
    std::vector<int> vector_1_3{5, 6, 2};
    std::vector<int> vector_1_4{6, 7, 3};

    std::vector<int> vector_1_5{3, 7, 8};
    std::vector<int> vector_1_6{1, 4, 8};
    std::vector<int> vector_1_7{1, 2, 4};
    std::vector<int> vector_1_8{5, 8, 6};

    std::vector<int> vector_1_9{1, 5, 2};
    std::vector<int> vector_1_10{2, 6, 3};
    std::vector<int> vector_1_11{4, 3, 8};
    std::vector<int> vector_1_12{5, 1, 8};

    expected_1.AddPolygon(vector_1_1);
    expected_1.AddPolygon(vector_1_2);
    expected_1.AddPolygon(vector_1_3);
    expected_1.AddPolygon(vector_1_4);
    expected_1.AddPolygon(vector_1_5);
    expected_1.AddPolygon(vector_1_6);
    expected_1.AddPolygon(vector_1_7);
    expected_1.AddPolygon(vector_1_8);
    expected_1.AddPolygon(vector_1_9);
    expected_1.AddPolygon(vector_1_10);
    expected_1.AddPolygon(vector_1_11);
    expected_1.AddPolygon(vector_1_12);

    expected_1.SetCountOfFacets(12);
    expected_1.SetCountOfVertexes(8);
    std::vector<double> buffer_vertexes_2{
        2.0, 2.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0,
        0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 2.0, 0.0, 2.0};
    for (double &i : buffer_vertexes_2) {
      expected_2.AddCoordinate(i);
    }
    std::vector<int> vector_2_1{1, 2, 3, 4};
    std::vector<int> vector_2_2{5, 6, 7, 8};

    expected_2.AddPolygon(vector_2_1);
    expected_2.AddPolygon(vector_2_2);

    expected_2.SetCountOfFacets(2);
    expected_2.SetCountOfVertexes(8);
  }
  s21::Data expected_1;
  s21::Data expected_2;
};

/* Function for equal data */
void EqualData(s21::Data expected, s21::Model *test_model) {
  ASSERT_EQ(*expected.GetCountOfFacets(), *test_model->GetCountOfFacets());
  ASSERT_EQ(*expected.GetCountOfVertexes(), *test_model->GetCountOfVertexes());
  for (unsigned i = 0; i < expected.GetCoordinates()->size(); i++) {
    ASSERT_DOUBLE_EQ(expected.GetCoordinates()->at(i),
                     test_model->GetCoordinates()->at(i));
  }
  for (int i = 0; i < *expected.GetCountOfFacets(); i++) {
    std::vector<int> &benchmark_vector = expected.GetPolygons()->at(i);
    std::vector<int> &test_model_vector = test_model->GetPolygons()->at(i);
    ASSERT_EQ(benchmark_vector.size(), test_model_vector.size());
    for (unsigned j = 0; j < benchmark_vector.size(); j++) {
      ASSERT_EQ(benchmark_vector.at(j), test_model_vector.at(j));
    }
  }
}

/* Test for positive file */
TEST_F(ParserTest, SuccessParsing_1) {
  // Arrange
  std::string file_name = "./tests/files_txt/cube.txt";
  // Act
  s21::Model *model = s21::Model::GetInstance();
  ;
  model->Parser(file_name);
  // Asseert
  EqualData(expected_1, model);
}

/* Test for negative file */
TEST_F(ParserTest, SuccessParsing_2) {
  // Arrange
  std::string file_name = "./tests/files_txt/cube_neg.txt";
  // Act
  s21::Model *model = s21::Model::GetInstance();
  ;
  model->ClearData();
  model->Parser(file_name);
  // Asseert
  EqualData(expected_2, model);
}

/* Test for not file */
TEST(ParseFilesTest, NotFileTest) {
  // Arrange
  std::string file_name = "./tests/files_txt/cube.tx";
  // Act
  s21::Model *model = s21::Model::GetInstance();
  model->ClearData();
  // Asseert
  ASSERT_THROW(model->Parser(file_name), std::invalid_argument);
}

/* Test incorrect vertex */
TEST(ParseFilesTest, IncorrectVertex) {
  // Arrange
  std::string file_name = "./tests/files_txt/fail1_cube.txt";
  // Act
  s21::Model *model = s21::Model::GetInstance();
  model->ClearData();
  // Asseert
  ASSERT_THROW(model->Parser(file_name), std::invalid_argument);
}

/* Test the number of polygons exceeding the number of vertices */
TEST(ParseFilesTest, IncorrectFacet) {
  // Arrange
  std::string file_name = "./tests/files_txt/fail2_cube.txt";
  // Act
  s21::Model *model = s21::Model::GetInstance();
  model->ClearData();
  // Asseert
  ASSERT_THROW(model->Parser(file_name), std::invalid_argument);
}

/* Test invalid polygon */
TEST(ParseFilesTest, IncorrectPolygon) {
  // Arrange
  std::string file_name = "./tests/files_txt/fail3_cube.txt";
  // Act
  s21::Model *model = s21::Model::GetInstance();
  model->ClearData();
  // Asseert
  ASSERT_THROW(model->Parser(file_name), std::invalid_argument);
}
