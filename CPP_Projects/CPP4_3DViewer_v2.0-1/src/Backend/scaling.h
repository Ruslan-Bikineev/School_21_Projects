#ifndef CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_SCALE_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_SCALE_H_

#include "model.h"

namespace s21 {

class Scaling {
 public:
  Scaling() : model_(Model::GetInstance()) {}
  void ScaleModel(double) noexcept;
  void CenterCoordinates() noexcept;

 protected:
  double CoefficientOfCentering(double, double) const noexcept;
  std::pair<double, double> FindMinMax(s21::Coords) const noexcept;

 private:
  Model *model_;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_SCALE_H_
