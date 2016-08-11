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
  add(result_str,"D","D");
  ck_assert_str_eq(result_str, "M");
}
END_TEST

START_TEST(test_add_XIV_and_LX)
{
    add(result_str,"XIV","LX");
    ck_assert_str_eq(result_str, "LXXIV");
}
END_TEST

START_TEST(test_add_XX_and_II)
{
    add(result_str,"XX","II");
    ck_assert_str_eq(result_str, "XXII");
}
END_TEST

START_TEST(test_add_MCMXCIX_and_I)
{
    add(result_str,"MCMXCIX","I");
    ck_assert_str_eq(result_str, "MM");
}
END_TEST

START_TEST(test_subtract_MCMXCIX_and_I)
{
    subtract(result_str,"MCMXCIX","I");
    ck_assert_str_eq(result_str, "MCMXCVIII");
}
END_TEST

START_TEST(test_subtract_MM_and_I)
{
    subtract(result_str,"MM","I");
    ck_assert_str_eq(result_str, "MCMXCIX");
}
END_TEST

START_TEST(test_subtract_CII_and_LV)
{
    subtract(result_str,"CII","LV");
    ck_assert_str_eq(result_str, "XLVII");
}
END_TEST

START_TEST(test_add_IM_and_Anything_gives_error)
{
  add(result_str,"IM","D");
}
END_TEST

START_TEST(test_add_Anything_and_IM_gives_error)
{
  add(result_str,"D","IM");
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
    tcase_add_test(test_roman_calculator, test_add_XIV_and_LX);
    tcase_add_test(test_roman_calculator, test_add_XX_and_II);
	tcase_add_test(test_roman_calculator, test_add_MCMXCIX_and_I);
    tcase_add_test(test_roman_calculator, test_subtract_MCMXCIX_and_I);
    tcase_add_test(test_roman_calculator, test_subtract_MM_and_I);
    tcase_add_test(test_roman_calculator, test_subtract_CII_and_LV);
    tcase_add_exit_test(test_roman_calculator, test_add_IM_and_Anything_gives_error, 1);
    tcase_add_exit_test(test_roman_calculator, test_add_Anything_and_IM_gives_error, 1);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
