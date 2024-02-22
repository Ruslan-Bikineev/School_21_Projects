#include "s21_tests.h"

int main() {
  // массив test suite с тест кейсами
  Suite *s21_tests[] = {create_matrix(),    remove_matrix(),  eq_matrix(),
                        sum_matrix(),       sub_matrix(),     mult_number(),
                        mult_matrix(),      transpose(),      determinant(),
                        calc_complements(), inverse_matrix(), NULL};

  int failed = 0;
  for (int i = 0; s21_tests[i] != NULL; i++) {
    // создаем под каждый suite SRunner и запускаем тесты
    SRunner *sr = srunner_create(s21_tests[i]);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
