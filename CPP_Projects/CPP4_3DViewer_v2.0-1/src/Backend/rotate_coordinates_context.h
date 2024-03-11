#ifndef CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_ROTATE_COORDINATES_CONTEXT_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_ROTATE_COORDINATES_CONTEXT_H_

#include <cmath>

#include "model.h"

namespace s21 {

class RotateCoordinates {
 public:
  virtual ~RotateCoordinates() = default;
  virtual void Rotate(const double, s21::Model *) const = 0;
};

class RotateCoordinatesContext {
 public:
  RotateCoordinatesContext(RotateCoordinates *rotate) : rotate_(rotate) {}
  ~RotateCoordinatesContext() { delete rotate_; }
  void DoRotateLogic(double angle) {
    rotate_->Rotate(angle, s21::Model::GetInstance());
  }

 private:
  s21::RotateCoordinates *rotate_;
};

class RotateX : public RotateCoordinates {
 public:
  ~RotateX() = default;
  void Rotate(const double angle, s21::Model *model) const override {
    for (unsigned i = 3; i < model->GetCoordinates()->size(); i += 3) {
      double temp_y = model->GetCoordinates()->at(i + kY);
      double temp_z = model->GetCoordinates()->at(i + kZ);
      model->GetCoordinates()->at(i + kY) =
          std::cos(angle) * temp_y - std::sin(angle) * temp_z;
      model->GetCoordinates()->at(i + kZ) =
          std::sin(angle) * temp_y + std::cos(angle) * temp_z;
    }
  }
};

class RotateY : public RotateCoordinates {
 public:
  ~RotateY() = default;
  void Rotate(const double angle, s21::Model *model) const override {
    for (unsigned i = 3; i < model->GetCoordinates()->size(); i += 3) {
      double temp_x = model->GetCoordinates()->at(i + kX);
      double temp_z = model->GetCoordinates()->at(i + kZ);
      model->GetCoordinates()->at(i + kX) =
          std::cos(angle) * temp_x - std::sin(angle) * temp_z;
      model->GetCoordinates()->at(i + kZ) =
          std::sin(angle) * temp_x + std::cos(angle) * temp_z;
    }
  }
};

class RotateZ : public RotateCoordinates {
 public:
  ~RotateZ() = default;
  void Rotate(const double angle, s21::Model *model) const override {
    for (unsigned i = 3; i < model->GetCoordinates()->size(); i += 3) {
      double temp_x = model->GetCoordinates()->at(i + kX);
      double temp_y = model->GetCoordinates()->at(i + kY);
      model->GetCoordinates()->at(i + kX) =
          std::cos(angle) * temp_x - std::sin(angle) * temp_y;
      model->GetCoordinates()->at(i + kY) =
          std::sin(angle) * temp_x + std::cos(angle) * temp_y;
    }
  }
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_ROTATE_COORDINATES_CONTEXT_H_
