#include <check.h>
#include <stdlib.h>
#include "roman_calculator.h"
#include "return_value_and_error_code.h"

char* result_str;
return_type result_value;

void setup(void)
{
    result_str = malloc(16);
    result_value.result_str = result_str;
}

void teardown(void)
{
    free(result_str);
}

START_TEST(test_add_D_and_D)
{
  add(&result_value,"D","D");
  ck_assert_str_eq(result_value.result_str, "M");
}
END_TEST

START_TEST(test_add_XIV_and_LX)
{
    add(&result_value,"XIV","LX");
    ck_assert_str_eq(result_value.result_str, "LXXIV");
}
END_TEST

START_TEST(test_add_XX_and_II)
{
    add(&result_value,"XX","II");
    ck_assert_str_eq(result_value.result_str, "XXII");
}
END_TEST

START_TEST(test_add_MCMXCIX_and_I)
{
    add(&result_value,"MCMXCIX","I");
    ck_assert_str_eq(result_value.result_str, "MM");
}
END_TEST

START_TEST(test_subtract_MCMXCIX_and_I)
{
    subtract(&result_value,"MCMXCIX","I");
    ck_assert_str_eq(result_value.result_str, "MCMXCVIII");
}
END_TEST

START_TEST(test_subtract_MM_and_I)
{
    subtract(&result_value,"MM","I");
    ck_assert_str_eq(result_value.result_str, "MCMXCIX");
}
END_TEST

START_TEST(test_subtract_CII_and_LV)
{
    subtract(&result_value,"CII","LV");
    ck_assert_str_eq(result_value.result_str, "XLVII");
    ck_assert_int_eq(result_value.error_code, 0);
}
END_TEST

START_TEST(test_add_IM_and_Anything_gives_error)
{
  add(&result_value,"IM","D");
  ck_assert_int_eq(result_value.error_code, 1);
  ck_assert_str_eq(result_value.result_str, "INVALID");
}
END_TEST

START_TEST(test_subtract_IM_and_Anything_gives_error)
{
  subtract(&result_value,"IM","D");
  ck_assert_int_eq(result_value.error_code, 1);
  ck_assert_str_eq(result_value.result_str, "INVALID");
}
END_TEST


START_TEST(test_add_Anything_and_IM_gives_error)
{
  add(&result_value,"D","IM");
  ck_assert_int_eq(result_value.error_code, 1);
  ck_assert_str_eq(result_value.result_str, "INVALID");
}
END_TEST

START_TEST(test_value_over_4000_entered_first_entry)
{
  subtract(&result_value,"MMMM","X");
  ck_assert_int_eq(result_value.error_code, 1);
  ck_assert_str_eq(result_value.result_str, "INVALID");
}
END_TEST

START_TEST(test_value_over_4000_entered_second_entry)
{
  add(&result_value,"X","MMMM");
  ck_assert_int_eq(result_value.error_code, 1);
  ck_assert_str_eq(result_value.result_str, "INVALID");
}
END_TEST

START_TEST(test_adding_values_gives_4000)
{
  add(&result_value,"MMM","M");
  ck_assert_int_eq(result_value.error_code, 1);
  ck_assert_str_eq(result_value.result_str, "INVALID");
}
END_TEST

START_TEST(test_subtraction_that_gives_negative_value_will_cause_error)
{
  subtract(&result_value,"L","M");
  ck_assert_int_eq(result_value.error_code, 1);
  ck_assert_str_eq(result_value.result_str, "INVALID");
}
END_TEST

START_TEST(test_subtraction_that_gives_zero_value_will_cause_error)
{
  subtract(&result_value,"L","L");
  ck_assert_int_eq(result_value.error_code, 1);
  ck_assert_str_eq(result_value.result_str, "INVALID");
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
    tcase_add_test(test_roman_calculator, test_add_IM_and_Anything_gives_error);
    tcase_add_test(test_roman_calculator, test_subtract_IM_and_Anything_gives_error);
    tcase_add_test(test_roman_calculator, test_add_Anything_and_IM_gives_error);
    tcase_add_test(test_roman_calculator, test_value_over_4000_entered_first_entry);
    tcase_add_test(test_roman_calculator, test_value_over_4000_entered_second_entry);
    tcase_add_test(test_roman_calculator, test_adding_values_gives_4000);
    tcase_add_test(test_roman_calculator, test_subtraction_that_gives_negative_value_will_cause_error);
    tcase_add_test(test_roman_calculator, test_subtraction_that_gives_zero_value_will_cause_error);
    
    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
