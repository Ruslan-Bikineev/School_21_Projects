#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "../Backend/affine_facade.h"
#include "../Backend/model.h"
#include "../Backend/move_coordinates_context.h"
#include "../Backend/scaling.h"

namespace s21 {

class MoveCoordinatesTest : public ::testing::Test {
 protected:
  void SetUp() override {
    model_ = Model::GetInstance();

    std::vector<double> buffer_vertexes_1{
        1.0, -1.0, -1.0, 1.0, -1.0, 1.0, -1.0, -1.0, 1.0, -1.0, -1.0, -1.0,
        1.0, 1.0,  -1.0, 1.0, 1.0,  1.0, -1.0, 1.0,  1.0, -1.0, 1.0,  -1.0};
    for (double &i : buffer_vertexes_1) {
      model_->AddCoordinate(i);
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

    model_->AddPolygon(vector_1_1);
    model_->AddPolygon(vector_1_2);
    model_->AddPolygon(vector_1_3);
    model_->AddPolygon(vector_1_4);
    model_->AddPolygon(vector_1_5);
    model_->AddPolygon(vector_1_6);
    model_->AddPolygon(vector_1_7);
    model_->AddPolygon(vector_1_8);
    model_->AddPolygon(vector_1_9);
    model_->AddPolygon(vector_1_10);
    model_->AddPolygon(vector_1_11);
    model_->AddPolygon(vector_1_12);

    model_->SetCountOfFacets(12);
    model_->SetCountOfVertexes(8);
  }

  Model *model_;
};

TEST_F(MoveCoordinatesTest, MoveXTest) {
  MoveX move_x;
  double delta_x = 2.0;
  move_x.Move(delta_x, model_);
}

TEST_F(MoveCoordinatesTest, MoveYTest) {
  MoveY move_y;
  double delta_y = 2.0;
  move_y.Move(delta_y, model_);
}

TEST_F(MoveCoordinatesTest, MoveZTest) {
  MoveZ move_z;
  double delta_z = 2.0;
  move_z.Move(delta_z, model_);
}

TEST_F(MoveCoordinatesTest, MoveContextTest) {
  MoveCoordinatesContext context(new MoveX());
  double delta = 2.0;
  context.DoMoveLogic(delta);
  model_->ClearData();
}

}  // namespace s21
