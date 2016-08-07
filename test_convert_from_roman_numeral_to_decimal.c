#include <check.h>
#include "convert_roman_to_decimal.h"

START_TEST(test_convert_I_to_decimal)
{
  ck_assert_int_eq(convert("I"), 1);
}
END_TEST

START_TEST(test_convert_II_to_decimal)
{
   ck_assert_int_eq(convert("II"), 2);
}
END_TEST

START_TEST(test_convert_III_to_decimal)
{
	ck_assert_int_eq(convert("III"), 3);
}
END_TEST

START_TEST(test_convert_V_to_decimal)
{
	ck_assert_int_eq(convert("V"), 5);
}
END_TEST

START_TEST(test_convert_IV_to_decimal)
{
	ck_assert_int_eq(convert("IV"), 4);
}
END_TEST

START_TEST(test_convert_X_to_decimal)
{
	ck_assert_int_eq(convert("X"), 10);
}
END_TEST

START_TEST(test_convert_IX_to_decimal_additional_coverage)
{
	ck_assert_int_eq(convert("IX"), 9);
}
END_TEST

START_TEST(test_convert_L_to_decimal)
{
	ck_assert_int_eq(convert("L"), 50);
}
END_TEST

START_TEST(test_convert_XL_to_decimal_additional_coverage)
{
	ck_assert_int_eq(convert("XL"), 40);
}
END_TEST

START_TEST(test_convert_C_to_decimal)
{
	ck_assert_int_eq(convert("C"), 100);
}
END_TEST

START_TEST(test_convert_XC_to_decimal_additional_coverage)
{
	ck_assert_int_eq(convert("XC"), 90);
}
END_TEST

START_TEST(test_convert_D_to_decimal)
{
	ck_assert_int_eq(convert("D"), 500);
}
END_TEST

START_TEST(test_convert_CD_to_decimal_additional_coverage)
{
	ck_assert_int_eq(convert("CD"), 400);
}
END_TEST

START_TEST(test_convert_M_to_decimal)
{
	ck_assert_int_eq(convert("M"), 1000);
}
END_TEST

START_TEST(test_convert_CM_to_decimal_additional_coverage)
{
	ck_assert_int_eq(convert("CM"), 900);
}
END_TEST

START_TEST(test_convert_MMMCMXCIX_to_decimal_additional_coverage)
{
	ck_assert_int_eq(convert("MMMCMXCIX"), 3999);
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, test_convert_I_to_decimal);
	tcase_add_test(tc1_1, test_convert_II_to_decimal);
	tcase_add_test(tc1_1, test_convert_III_to_decimal);
	tcase_add_test(tc1_1, test_convert_V_to_decimal);
	tcase_add_test(tc1_1, test_convert_IV_to_decimal);
	tcase_add_test(tc1_1, test_convert_X_to_decimal);
	tcase_add_test(tc1_1, test_convert_IX_to_decimal_additional_coverage);
	tcase_add_test(tc1_1, test_convert_L_to_decimal);
	tcase_add_test(tc1_1, test_convert_XL_to_decimal_additional_coverage);
	tcase_add_test(tc1_1, test_convert_C_to_decimal);
	tcase_add_test(tc1_1, test_convert_XC_to_decimal_additional_coverage);
	tcase_add_test(tc1_1, test_convert_D_to_decimal);
	tcase_add_test(tc1_1, test_convert_CD_to_decimal_additional_coverage);
	tcase_add_test(tc1_1, test_convert_M_to_decimal);
	tcase_add_test(tc1_1, test_convert_CM_to_decimal_additional_coverage);
	tcase_add_test(tc1_1, test_convert_MMMCMXCIX_to_decimal_additional_coverage);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
