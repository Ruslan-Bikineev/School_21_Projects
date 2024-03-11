#include "scaling.h"

namespace s21 {

/* Centering coordinates */
void Scaling::CenterCoordinates() noexcept {
  auto min_max_x = FindMinMax(kX);
  auto min_max_y = FindMinMax(kY);
  auto min_max_z = FindMinMax(kZ);
  double centr_x = CoefficientOfCentering(min_max_x.first, min_max_x.second);
  double centr_y = CoefficientOfCentering(min_max_y.first, min_max_y.second);
  double centr_z = CoefficientOfCentering(min_max_z.first, min_max_z.second);
  for (size_t i = 3; i < model_->GetCoordinates()->size(); i += 3) {
    model_->GetCoordinates()->at(i + kX) -= centr_x;
    model_->GetCoordinates()->at(i + kY) -= centr_y;
    model_->GetCoordinates()->at(i + kZ) -= centr_z;
  }
}

/* Scaling model */
void Scaling::ScaleModel(double scale) noexcept {
  auto min_max_x = FindMinMax(kX);
  auto min_max_y = FindMinMax(kY);
  auto min_max_z = FindMinMax(kZ);
  double max_num = std::max(min_max_x.second - min_max_x.first,
                            min_max_y.second - min_max_y.first);
  max_num = std::max(max_num, min_max_z.second - min_max_z.first);

  double coefficient_scale = (2.0 * scale) / max_num;

  for (double &coordinate : *model_->GetCoordinates()) {
    coordinate *= coefficient_scale;
  }
}

/* Find min and max */
std::pair<double, double> Scaling::FindMinMax(
    s21::Coords coords) const noexcept {
  double min = model_->GetCoordinates()->at(coords);
  double max = model_->GetCoordinates()->at(coords);
  for (size_t i = coords; i < model_->GetCoordinates()->size(); i += 3) {
    max = std::max(max, model_->GetCoordinates()->at(i));
    min = std::min(min, model_->GetCoordinates()->at(i));
  }
  return {min, max};
}

/* Calculationing coefficient of centering */
double Scaling::CoefficientOfCentering(double min, double max) const noexcept {
  return min + (max - min) / 2.0;
}

}  // namespace s21
