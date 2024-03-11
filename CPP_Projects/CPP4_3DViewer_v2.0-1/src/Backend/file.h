#ifndef CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_FILE_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_FILE_H_

#include <fstream>
#include <iostream>

namespace s21 {

class File {
 public:
  File() = default;
  bool IsEndOfFile() noexcept;
  void OpenFile(std::string);
  const std::string GetLine() noexcept;
  ~File() { file_.close(); };

 private:
  std::ifstream file_;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_BACKEND_FILE_H_
