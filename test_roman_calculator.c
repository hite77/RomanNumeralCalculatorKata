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

START_TEST(test_add_XIV_and_LX)
{
    add("XIV","LX",result_str);
    ck_assert_str_eq(result_str, "LXXIV");
}
END_TEST

START_TEST(test_add_XX_and_II)
{
    add("XX","II",result_str);
    ck_assert_str_eq(result_str, "XXII");
}
END_TEST

START_TEST(test_add_MCMXCIX_and_I)
{
    add("MCMXCIX","I",result_str);
    ck_assert_str_eq(result_str, "MM");
}
END_TEST

START_TEST(test_subtract_MCMXCIX_and_I)
{
    subtract("MCMXCIX","I",result_str);
    ck_assert_str_eq(result_str, "MCMXCVIII");
}
END_TEST

START_TEST(test_subtract_MM_and_I)
{
    subtract("MM","I",result_str);
    ck_assert_str_eq(result_str, "MCMXCIX");
}
END_TEST

START_TEST(test_subtract_CII_and_LV)
{
    subtract("CII","LV",result_str);
    ck_assert_str_eq(result_str, "XLVII");
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
    
    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
