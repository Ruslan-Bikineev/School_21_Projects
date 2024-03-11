#ifndef CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_AFFINE_FACADE_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_AFFINE_FACADE_H_

#include "controller.h"
#include "move_coordinates_context.h"
#include "rotate_coordinates_context.h"
#include "scaling.h"

namespace s21 {
class AffineFacade : public Scaling {
 public:
  AffineFacade() { model_ = Model::GetInstance(); };
  ~AffineFacade() {
    delete move_coord_x_;
    delete move_coord_y_;
    delete move_coord_z_;
    delete rotate_coord_x_;
    delete rotate_coord_y_;
    delete rotate_coord_z_;
  }
  const double *GetScale() { return &scale_; }
  const double *GetMoveX() { return &move_x_; }
  const double *GetMoveY() { return &move_y_; }
  const double *GetMoveZ() { return &move_z_; }
  const double *GetRotateX() { return &rotate_x_; }
  const double *GetRotateY() { return &rotate_y_; }
  const double *GetRotateZ() { return &rotate_z_; }
  void SetScale(const double scale) { scale_ = scale; }
  const double *GetPrevScale() { return &prev_scale_; }
  const double *GetPrevMoveX() { return &prev_move_x_; }
  const double *GetPrevMoveY() { return &prev_move_y_; }
  const double *GetPrevMoveZ() { return &prev_move_z_; }
  void SetMoveX(const double move_x) { move_x_ = move_x; }
  void SetMoveY(const double move_y) { move_y_ = move_y; }
  void SetMoveZ(const double move_z) { move_z_ = move_z; }
  const double *GetPrevRotateX() { return &prev_rotate_x_; }
  const double *GetPrevRotateY() { return &prev_rotate_y_; }
  const double *GetPrevRotateZ() { return &prev_rotate_z_; }
  void SetRotateX(const double rotate_x) { rotate_x_ = rotate_x; }
  void SetRotateY(const double rotate_y) { rotate_y_ = rotate_y; }
  void SetRotateZ(const double rotate_z) { rotate_z_ = rotate_z; }
  void SetPrevScale(const double prev_scale) { prev_scale_ = prev_scale; }
  void SetPrevMoveX(const double prev_move_x) { prev_move_x_ = prev_move_x; }
  void SetPrevMoveY(const double prev_move_y) { prev_move_y_ = prev_move_y; }
  void SetPrevMoveZ(const double prev_move_z) { prev_move_z_ = prev_move_z; }
  void SetPrevRotateX(const double prev_rotate_x) {
    prev_rotate_x_ = prev_rotate_x;
  }
  void SetPrevRotateY(const double prev_rotate_y) {
    prev_rotate_y_ = prev_rotate_y;
  }
  void SetPrevRotateZ(const double prev_rotate_z) {
    prev_rotate_z_ = prev_rotate_z;
  }
  void UpdatePrevValues() {
    prev_scale_ = scale_;
    prev_move_x_ = move_x_;
    prev_move_y_ = move_y_;
    prev_move_z_ = move_z_;
    prev_rotate_x_ = rotate_x_;
    prev_rotate_y_ = rotate_y_;
    prev_rotate_z_ = rotate_z_;
  }
  void DoAffine() {
    if (prev_scale_ != scale_) {
      ScaleModel(scale_);
    }
    if (prev_rotate_x_ != rotate_x_) {
      rotate_coord_x_->DoRotateLogic(rotate_x_ - prev_rotate_x_);
    }
    if (prev_rotate_y_ != rotate_y_) {
      rotate_coord_y_->DoRotateLogic(rotate_y_ - prev_rotate_y_);
    }
    if (prev_rotate_z_ != rotate_z_) {
      rotate_coord_z_->DoRotateLogic(rotate_z_ - prev_rotate_z_);
    }
    if (prev_move_x_ != move_x_) {
      move_coord_x_->DoMoveLogic(move_x_ - prev_move_x_);
    }
    if (prev_move_y_ != move_y_) {
      move_coord_y_->DoMoveLogic(prev_move_y_ - move_y_);
    }
    if (prev_move_z_ != move_z_) {
      move_coord_z_->DoMoveLogic(prev_move_z_ - move_z_);
    }
  }

 private:
  Model *model_;
  double scale_ = 1;
  double move_x_ = 0;
  double move_y_ = 0;
  double move_z_ = 0;
  double rotate_x_ = 0;
  double rotate_y_ = 0;
  double rotate_z_ = 0;
  double prev_scale_ = 0;
  double prev_move_x_ = 0;
  double prev_move_y_ = 0;
  double prev_move_z_ = 0;
  double prev_rotate_x_ = 0;
  double prev_rotate_y_ = 0;
  double prev_rotate_z_ = 0;
  MoveCoordinatesContext *move_coord_x_{
      new s21::MoveCoordinatesContext(new s21::MoveX())};
  MoveCoordinatesContext *move_coord_y_{
      new s21::MoveCoordinatesContext(new s21::MoveY())};
  MoveCoordinatesContext *move_coord_z_{
      new s21::MoveCoordinatesContext(new s21::MoveZ())};
  RotateCoordinatesContext *rotate_coord_x_{
      new s21::RotateCoordinatesContext(new s21::RotateX())};
  RotateCoordinatesContext *rotate_coord_y_{
      new s21::RotateCoordinatesContext(new s21::RotateY())};
  RotateCoordinatesContext *rotate_coord_z_{
      new s21::RotateCoordinatesContext(new s21::RotateZ())};
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_AFFINE_FACADE_H_
