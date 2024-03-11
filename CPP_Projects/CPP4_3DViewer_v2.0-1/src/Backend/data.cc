#include "data.h"

namespace s21 {

/* Constructors */
Data::Data()
    : count_of_facets_(0),
      count_of_vertexes_(0),
      coordinates_({0.0, 0.0, 0.0}),
      polygons_(){};

/* Get coordinates */
std::vector<double> *Data::GetCoordinates() noexcept { return &coordinates_; }

/* Get count of facets */
const int *Data::GetCountOfFacets() const noexcept { return &count_of_facets_; }

/* Get polygons */
std::vector<std::vector<int>> *Data::GetPolygons() noexcept {
  return &polygons_;
}

/* Get count of vertexes */
const int *Data::GetCountOfVertexes() const noexcept {
  return &count_of_vertexes_;
}

/* Add coordinate */
void Data::AddCoordinate(const double number) noexcept {
  coordinates_.push_back(number);
}

/* Set count of facets */
void Data::SetCountOfFacets(const int number) noexcept {
  count_of_facets_ = number;
}

/* Add polygon */
void Data::AddPolygon(const std::vector<int> vector) noexcept {
  polygons_.push_back(vector);
  ++count_of_facets_;
}

/* Set count of vertexes */
void Data::SetCountOfVertexes(const int number) noexcept {
  count_of_vertexes_ = number;
}

void Data::ClearData() noexcept {
  coordinates_.clear();
  coordinates_ = {0, 0, 0};
  polygons_.clear();
  count_of_facets_ = 0;
  count_of_vertexes_ = 0;
}

}  // namespace s21