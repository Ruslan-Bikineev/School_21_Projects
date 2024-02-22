#include "s21_string_tests.h"

int main() {
  // массив test suite с тест кейсами
  Suite *s21_string_tests[] = {sscanf_test_c(),    sscanf_test_n(),
                               sscanf_test_d(),    sscanf_test_u(),
                               sscanf_test_o(),    sscanf_test_x(),
                               sscanf_test_p(),    sscanf_test_real(),
                               sscanf_test_i(),    sscanf_test_s(),
                               string_funcs(),     sprintf_test_c(),
                               sprintf_test_d(),   sprintf_test_f(),
                               sprintf_test_s(),   sprintf_test_x_X(),
                               sprintf_test_p(),   sprintf_test_o(),
                               sprintf_test_e_E(), sprintf_test_g_G(),
                               sprintf_test_u(),   S21_NULL};

  int failed = 0;
  for (int i = 0; s21_string_tests[i] != S21_NULL; i++) {
    // создаем под каждый suite SRunner и запускаем тесты
    SRunner *sr = srunner_create(s21_string_tests[i]);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}