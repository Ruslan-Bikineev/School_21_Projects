#ifndef CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_DATA_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_DATA_H_

#include <iostream>
#include <vector>

namespace s21 {

enum Coords { kX, kY, kZ };
enum TypesLines { kSolid, kDashed };
enum TypesVertexes { kNone, kCircle, kSquare };
enum TypesProjection { kCentral, kOrthogonal };

class Data {
 public:
  /*--------------------------CONSTRUCTORS---------------------------*/
  Data();
  /*----------------------------FUNCTIONS----------------------------*/
  void ClearData() noexcept;
  void AddCoordinate(const double) noexcept;
  void SetCountOfFacets(const int) noexcept;
  void SetCountOfVertexes(const int) noexcept;
  const int *GetCountOfFacets() const noexcept;
  std::vector<double> *GetCoordinates() noexcept;
  const int *GetCountOfVertexes() const noexcept;
  void AddPolygon(const std::vector<int>) noexcept;
  std::vector<std::vector<int>> *GetPolygons() noexcept;

 private:
  int count_of_facets_;
  int count_of_vertexes_;
  std::vector<double> coordinates_;
  std::vector<std::vector<int>> polygons_;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_DATA_H_
