#ifndef CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_MOVE_COORDINATES_CONTEXT_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_MOVE_COORDINATES_CONTEXT_H_

#include "model.h"

namespace s21 {

class MoveCoordinates {
 public:
  virtual ~MoveCoordinates() = default;
  virtual void Move(const double, s21::Model *) const = 0;
};

class MoveCoordinatesContext {
 public:
  MoveCoordinatesContext(MoveCoordinates *move) : move_(move){};
  ~MoveCoordinatesContext() { delete move_; }
  void DoMoveLogic(double move) {
    move_->Move(move, s21::Model::GetInstance());
  }

 private:
  MoveCoordinates *move_;
};

class MoveX : public MoveCoordinates {
 public:
  ~MoveX() = default;
  void Move(const double x, s21::Model *model) const override {
    for (size_t i = 3; i < model->GetCoordinates()->size(); i += 3) {
      model->GetCoordinates()->at(i) += x;
    }
  }
};

class MoveY : public MoveCoordinates {
 public:
  ~MoveY() = default;
  void Move(const double y, s21::Model *model) const override {
    for (size_t i = 4; i < model->GetCoordinates()->size(); i += 3) {
      model->GetCoordinates()->at(i) += y;
    }
  }
};

class MoveZ : public MoveCoordinates {
 public:
  ~MoveZ() = default;
  void Move(const double z, s21::Model *model) const override {
    for (size_t i = 5; i < model->GetCoordinates()->size(); i += 3) {
      model->GetCoordinates()->at(i) += z;
    }
  }
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_MOVE_COORDINATES_CONTEXT_H_
