#include "model.h"

namespace s21 {

void Model::Parser(std::string file_way) {
  s21::File file;
  file.OpenFile(file_way);
  std::string line;
  std::regex pattern_vertex(
      "^v(\\s+-?[0-9]+(\\.([0-9]+)(e-[0-9]+)?)?){3}\\s*(\\s1\\.0)?\\s*$",
      std::regex_constants::optimize);
  std::regex pattern_polygon(
      "^f\\s+(-?[0-9]+\\s*|-?[0-9]+\\/[0-9]+\\s*|-?[0-9]+\\/\\/"
      "-?[0-9]+\\s*|(-?[0-9]+\\/){2}-?[0-9]+\\s*){2,}$",
      std::regex_constants::optimize);
  while (!file.IsEndOfFile()) {
    line = file.GetLine();
    if (line[0] == 'v' && line[1] == ' ') {
      if (std::regex_match(line, pattern_vertex)) {
        ParserVertexs(&line);
      } else {
        throw std::invalid_argument("Model::Parser()::Regex: Invalid vertex");
      }
    } else if (line[0] == 'f' && line[1] == ' ') {
      if (std::regex_match(line, pattern_polygon)) {
        ParserFacets(&line);
      } else {
        throw std::invalid_argument("Model::Parser()::Regex: Invalid polygon");
      }
    }
  }
}
void Model::ParserVertexs(std::string *line) {
  char *ch_ptr = line->data();
  ch_ptr += 2;
  for (int i = 0; i < 3; i++) {
    AddCoordinate(std::strtod(ch_ptr, &ch_ptr));
  }
  SetCountOfVertexes(*GetCountOfVertexes() + 1);
}

void Model::ParserFacets(std::string *line) {
  std::vector<int> vector;
  char *ch_ptr = line->data();
  ch_ptr += 2;
  char *token = std::strtok(ch_ptr, " ");
  for (int temp = 0; token != nullptr && *token != '\r';) {
    temp = std::stoi(token);
    if (temp == 0 || std::abs(temp) > *GetCountOfVertexes()) {
      throw std::invalid_argument("Model::ParserFacets(): Invalid facet");
    } else {
      vector.push_back(temp < 0 ? temp + *GetCountOfVertexes() + 1 : temp);
    }
    token = std::strtok(nullptr, " ");
  }
  AddPolygon(vector);
}

}  // namespace s21
