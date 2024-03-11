#ifndef CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_MODEL_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_MODEL_H_

#include <regex>

#include "cstring"
#include "data.h"
#include "file.h"

namespace s21 {

class Model : public s21::Data {
 public:
  static Model *GetInstance() {
    static Model instance;
    return &instance;
  }
  void Parser(std::string);
  Model(Model &) = delete;
  void operator=(const Model &) = delete;

 private:
  Model() : s21::Data(){};
  void ParserFacets(std::string *);
  void ParserVertexs(std::string *);
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_MODEL_H_
