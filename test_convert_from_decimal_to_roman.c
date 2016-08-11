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
  convert_to_roman(result_str, 1000);	
  ck_assert_str_eq(result_str, "M");
}
END_TEST

START_TEST(test_convert_2000_to_roman)
{
  convert_to_roman(result_str, 2000);
  ck_assert_str_eq(result_str, "MM");
}
END_TEST

START_TEST(test_convert_3000_to_roman_added_coverage)
{
  convert_to_roman(result_str, 3000);
  ck_assert_str_eq(result_str, "MMM");
}
END_TEST

START_TEST(test_convert_100_to_roman)
{
  convert_to_roman(result_str, 100);
  ck_assert_str_eq(result_str, "C");
}
END_TEST

START_TEST(test_convert_200_to_roman)
{
  convert_to_roman(result_str, 200);
  ck_assert_str_eq(result_str, "CC");
}
END_TEST

START_TEST(test_convert_1200_to_roman)
{
  convert_to_roman(result_str, 1200);
  ck_assert_str_eq(result_str, "MCC");
}
END_TEST

START_TEST(test_convert_1300_to_roman)
{
  convert_to_roman(result_str, 1300);
  ck_assert_str_eq(result_str, "MCCC");
}
END_TEST

START_TEST(test_convert_400_to_roman)
{
  convert_to_roman(result_str, 400);
  ck_assert_str_eq(result_str, "CD");
}
END_TEST

START_TEST(test_convert_500_to_roman)
{
  convert_to_roman(result_str, 500);
  ck_assert_str_eq(result_str, "D");
}
END_TEST

START_TEST(test_convert_600_to_roman)
{
  convert_to_roman(result_str, 600);
  ck_assert_str_eq(result_str, "DC");
}
END_TEST

START_TEST(test_convert_700_to_roman)
{
  convert_to_roman(result_str, 700);
  ck_assert_str_eq(result_str, "DCC");
}
END_TEST

START_TEST(test_convert_800_to_roman)
{
  convert_to_roman(result_str, 800);
  ck_assert_str_eq(result_str, "DCCC");
}
END_TEST

START_TEST(test_convert_900_to_roman)
{
  convert_to_roman(result_str, 900);
  ck_assert_str_eq(result_str, "CM");
}
END_TEST

START_TEST(test_convert_110_to_roman)
{
  convert_to_roman(result_str, 110);
  ck_assert_str_eq(result_str, "CX");
}
END_TEST

START_TEST(test_convert_20_to_roman)
{
  convert_to_roman(result_str, 20);
  ck_assert_str_eq(result_str, "XX");
}
END_TEST

START_TEST(test_convert_30_to_roman)
{
  convert_to_roman(result_str ,30);
  ck_assert_str_eq(result_str, "XXX");
}
END_TEST

START_TEST(test_convert_40_to_roman)
{
  convert_to_roman(result_str, 40);
  ck_assert_str_eq(result_str, "XL");
}
END_TEST

START_TEST(test_convert_50_to_roman)
{
  convert_to_roman(result_str, 50);
  ck_assert_str_eq(result_str, "L");
}
END_TEST

START_TEST(test_convert_60_to_roman)
{
  convert_to_roman(result_str, 60);
  ck_assert_str_eq(result_str, "LX");
}
END_TEST

START_TEST(test_convert_70_to_roman)
{
  convert_to_roman(result_str, 70);
  ck_assert_str_eq(result_str, "LXX");
}
END_TEST

START_TEST(test_convert_80_to_roman)
{
  convert_to_roman(result_str, 80);
  ck_assert_str_eq(result_str, "LXXX");
}
END_TEST

START_TEST(test_convert_90_to_roman)
{
  convert_to_roman(result_str, 90);
  ck_assert_str_eq(result_str, "XC");
}
END_TEST

START_TEST(test_convert_1_to_roman)
{
  convert_to_roman(result_str, 1);
  ck_assert_str_eq(result_str, "I");
}
END_TEST

START_TEST(test_convert_2_to_roman)
{
  convert_to_roman(result_str, 2);
  ck_assert_str_eq(result_str, "II");
}
END_TEST

START_TEST(test_convert_3_to_roman)
{
  convert_to_roman(result_str, 3);
  ck_assert_str_eq(result_str, "III");
}
END_TEST

START_TEST(test_convert_4_to_roman)
{
  convert_to_roman(result_str, 4);
  ck_assert_str_eq(result_str, "IV");
}
END_TEST

START_TEST(test_convert_5_to_roman)
{
  convert_to_roman(result_str, 5);
  ck_assert_str_eq(result_str, "V");
}
END_TEST

START_TEST(test_convert_6_to_roman)
{
  convert_to_roman(result_str, 6);
  ck_assert_str_eq(result_str, "VI");
}
END_TEST

START_TEST(test_convert_7_to_roman)
{
  convert_to_roman(result_str, 7);
  ck_assert_str_eq(result_str, "VII");
}
END_TEST

START_TEST(test_convert_8_to_roman)
{
  convert_to_roman(result_str, 8);
  ck_assert_str_eq(result_str, "VIII");
}
END_TEST

START_TEST(test_convert_9_to_roman)
{
  convert_to_roman(result_str, 9);
  ck_assert_str_eq(result_str, "IX");
}
END_TEST

START_TEST(test_convert_3888_to_roman)
{
  convert_to_roman(result_str, 3888);
  ck_assert_str_eq(result_str, "MMMDCCCLXXXVIII");
}
END_TEST

START_TEST(test_convert_3999_to_roman)
{
  convert_to_roman(result_str, 3999);
  ck_assert_str_eq(result_str, "MMMCMXCIX");
}
END_TEST

START_TEST(test_convert_2479_to_roman)
{
  convert_to_roman(result_str, 2479);
  ck_assert_str_eq(result_str, "MMCDLXXIX");
}
END_TEST

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
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_400_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_500_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_600_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_700_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_800_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_900_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_110_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_20_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_30_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_40_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_50_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_60_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_70_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_80_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_90_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_1_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_2_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_3_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_4_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_5_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_6_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_7_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_8_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_9_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_3888_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_3999_to_roman);
  	tcase_add_test(test_convert_decimal_to_roman, test_convert_2479_to_roman);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
