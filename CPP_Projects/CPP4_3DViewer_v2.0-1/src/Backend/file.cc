#include "file.h"

namespace s21 {
/* Open file */
void File::OpenFile(std::string way) {
  file_.open(way);
  if (!file_) {
    throw std::invalid_argument("File::OpenFile(), File not found!");
  }
}

/* Return true when pointer on file is end */
bool File::IsEndOfFile() noexcept { return file_.eof(); }

/* Get line from file */
const std::string File::GetLine() noexcept {
  std::string line;
  std::getline(file_, line);
  return line;
}

}  // namespace s21