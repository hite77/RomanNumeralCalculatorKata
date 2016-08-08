#include <check.h>
#include <stdlib.h>
#include "convert_decimal_to_roman.h"

char* result_str;

void setup(void)
{
	result_str = malloc(16);
}

void teardown(void)
{
	free(result_str);
}

START_TEST(test_convert_1000_to_roman)
{
  convert_to_roman(1000, result_str);	
  ck_assert_str_eq(result_str, "M");
}
END_TEST

START_TEST(test_convert_2000_to_roman)
{
  convert_to_roman(2000, result_str);
  ck_assert_str_eq(result_str, "MM");
}
END_TEST

START_TEST(test_convert_3000_to_roman_added_coverage)
{
  convert_to_roman(3000, result_str);
  ck_assert_str_eq(result_str, "MMM");
}
END_TEST

START_TEST(test_convert_100_to_roman)
{
  convert_to_roman(100, result_str);
  ck_assert_str_eq(result_str, "C");
}
END_TEST

START_TEST(test_convert_200_to_roman)
{
  convert_to_roman(200, result_str);
  ck_assert_str_eq(result_str, "CC");
}
END_TEST

START_TEST(test_convert_1200_to_roman)
{
  convert_to_roman(1200, result_str);
  ck_assert_str_eq(result_str, "MCC");
}
END_TEST

START_TEST(test_convert_1300_to_roman)
{
  convert_to_roman(1300, result_str);
  ck_assert_str_eq(result_str, "MCCC");
}
END_TEST

// test for 3888 MMMDCCCLXXXVIII
// test for 3999 MMMCMXCIX

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *test_convert_decimal_to_roman = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, test_convert_decimal_to_roman);
    tcase_add_checked_fixture(test_convert_decimal_to_roman, setup, teardown);
    tcase_add_test(test_convert_decimal_to_roman, test_convert_1000_to_roman);
	tcase_add_test(test_convert_decimal_to_roman, test_convert_2000_to_roman);
	tcase_add_test(test_convert_decimal_to_roman, test_convert_3000_to_roman_added_coverage);
	tcase_add_test(test_convert_decimal_to_roman, test_convert_100_to_roman);
	tcase_add_test(test_convert_decimal_to_roman, test_convert_200_to_roman);
	tcase_add_test(test_convert_decimal_to_roman, test_convert_1200_to_roman);
	tcase_add_test(test_convert_decimal_to_roman, test_convert_1300_to_roman);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
