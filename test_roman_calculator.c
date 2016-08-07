#include <check.h>
#include <stdlib.h>
#include "roman_calculator.h"

char* result_str;

void setup(void)
{
    result_str = malloc(16);
}

void teardown(void)
{
    free(result_str);
}

START_TEST(test_add_D_and_D)
{
  add("D","D",result_str);
  ck_assert_str_eq(result_str, "M");
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *test_roman_calculator = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, test_roman_calculator);
    tcase_add_checked_fixture(test_roman_calculator, setup, teardown);
    tcase_add_test(test_roman_calculator, test_add_D_and_D);
	
    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
