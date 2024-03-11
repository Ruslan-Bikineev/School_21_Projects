#include "./Backend/controller.h"
#include "./Backend/data.h"
#include "./Backend/file.h"
#include "./Backend/model.h"
#include "./Backend/move_coordinates_context.h"

int main() {
  // std::string input_file = "./tests/files_txt/cube_neg.txt";
  // std::string input_file = "./obj_files/cube.obj";
  // std::string input_file = "./tests/files_txt/cube.txt";
  // std::string input_file = "./tests/files_txt/fail2_cube.txt";
  std::string input_file = "./tests/files_txt/fail3_cube.txt";
  // std::string input_file = "../src/obj_files/cube.obj";

  s21::Model *model = s21::Model::GetInstance();
  s21::Controller controller(model);
  controller.DataPreparation(input_file);
  model->PrintData();

  return 0;
}