#include "s21_tests.h"

#include "math.h"

int main() {
  // массив test suite с тест кейсами
  Suite *s21_tests[] = {dec_to_float_tests(), negate_tests(),
                        truncate_tests(),     floor_tests(),
                        round_tests(),        greater_tests(),
                        less_tests(),         equal_tests(),
                        addition_tests(),     mul_tests(),
                        sub_tests(),          div_tests(),
                        int_to_dec_tests(),   dec_to_int_tests(),
                        float_to_dec_tests(), NULL};

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
