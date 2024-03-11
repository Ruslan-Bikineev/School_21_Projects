#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "../Backend/affine_facade.h"
#include "../Backend/model.h"
#include "../Backend/move_coordinates_context.h"
#include "../Backend/scaling.h"

namespace s21 {

class ScalingTest : public ::testing::Test {
 protected:
  void SetUp() { model_ = Model::GetInstance(); }

  Model *model_;
  Scaling *scaling = new Scaling();
};

TEST_F(ScalingTest, CenterCoordinatesTest) { scaling->CenterCoordinates(); }

TEST_F(ScalingTest, ScaleModelTest) {
  double scale_factor = 2.0;
  scaling->ScaleModel(scale_factor);
  model_->ClearData();
}

}  // namespace s21
