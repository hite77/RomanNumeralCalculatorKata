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
}
END_TEST

// START_TEST(test_add_IM_and_Anything_gives_error)
// {
//   add(result_str,"IM","D");
// }
// END_TEST

// START_TEST(test_add_Anything_and_IM_gives_error)
// {
//   add(result_str,"D","IM");
// }
// END_TEST

// START_TEST(test_value_over_4000_entered_first_entry)
// {
//   subtract(result_str,"MMMM","X");
// }
// END_TEST

// START_TEST(test_value_over_4000_entered_second_entry)
// {
//   add(result_str,"X","MMMM");
// }
// END_TEST

// START_TEST(test_adding_values_gives_4000)
// {
//   add(result_str,"MMM","M");
// }
// END_TEST

// START_TEST(test_subtraction_that_gives_negative_value_will_cause_error)
// {
//   subtract(result_str,"L","M");
// }
// END_TEST

// START_TEST(test_subtraction_that_gives_zero_value_will_cause_error)
// {
//   subtract(result_str,"L","L");
// }
// END_TEST

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
    //tcase_add_exit_test(test_roman_calculator, test_add_IM_and_Anything_gives_error, 1);
    //tcase_add_exit_test(test_roman_calculator, test_add_Anything_and_IM_gives_error, 1);
    //tcase_add_exit_test(test_roman_calculator, test_value_over_4000_entered_first_entry, 2);
    //tcase_add_exit_test(test_roman_calculator, test_value_over_4000_entered_second_entry, 2);
    //tcase_add_exit_test(test_roman_calculator, test_adding_values_gives_4000, 2);
    //tcase_add_exit_test(test_roman_calculator, test_subtraction_that_gives_negative_value_will_cause_error, 4);
    //tcase_add_exit_test(test_roman_calculator, test_subtraction_that_gives_zero_value_will_cause_error, 4);
    
    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
