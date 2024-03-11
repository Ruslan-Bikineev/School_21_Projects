#ifndef CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_CONTROLLER_H
#define CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_CONTROLLER_H

#include "model.h"

namespace s21 {

class Controller {
 public:
  Controller(Model *model) : model_(model){};
  void DataPreparation(std::string file_way) {
    model_->ClearData();
    model_->Parser(file_way);
  }
  std::vector<std::vector<int>> *GetPolygons() { return model_->GetPolygons(); }
  std::vector<double> *GetCoordinates() { return model_->GetCoordinates(); }
  const int *GetCountOfVertexes() { return model_->GetCountOfVertexes(); }

 private:
  Model *model_;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_CONTROLLER_H
