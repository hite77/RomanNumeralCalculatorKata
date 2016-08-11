#include <check.h>
#include "convert_roman_to_decimal.h"

START_TEST(test_convert_I_to_decimal)
{
  ck_assert_int_eq(convert_to_decimal("I"), 1);
}
END_TEST

START_TEST(test_convert_II_to_decimal)
{
   ck_assert_int_eq(convert_to_decimal("II"), 2);
}
END_TEST

START_TEST(test_convert_III_to_decimal)
{
	ck_assert_int_eq(convert_to_decimal("III"), 3);
}
END_TEST

START_TEST(test_convert_V_to_decimal)
{
	ck_assert_int_eq(convert_to_decimal("V"), 5);
}
END_TEST

START_TEST(test_convert_IV_to_decimal)
{
	ck_assert_int_eq(convert_to_decimal("IV"), 4);
}
END_TEST

START_TEST(test_convert_X_to_decimal)
{
	ck_assert_int_eq(convert_to_decimal("X"), 10);
}
END_TEST

START_TEST(test_convert_IX_to_decimal_additional_coverage)
{
	ck_assert_int_eq(convert_to_decimal("IX"), 9);
}
END_TEST

START_TEST(test_convert_L_to_decimal)
{
	ck_assert_int_eq(convert_to_decimal("L"), 50);
}
END_TEST

START_TEST(test_convert_XL_to_decimal_additional_coverage)
{
	ck_assert_int_eq(convert_to_decimal("XL"), 40);
}
END_TEST

START_TEST(test_convert_C_to_decimal)
{
	ck_assert_int_eq(convert_to_decimal("C"), 100);
}
END_TEST

START_TEST(test_convert_XC_to_decimal_additional_coverage)
{
	ck_assert_int_eq(convert_to_decimal("XC"), 90);
}
END_TEST

START_TEST(test_convert_D_to_decimal)
{
	ck_assert_int_eq(convert_to_decimal("D"), 500);
}
END_TEST

START_TEST(test_convert_CD_to_decimal_additional_coverage)
{
	ck_assert_int_eq(convert_to_decimal("CD"), 400);
}
END_TEST

START_TEST(test_convert_M_to_decimal)
{
	ck_assert_int_eq(convert_to_decimal("M"), 1000);
}
END_TEST

START_TEST(test_convert_CM_to_decimal_additional_coverage)
{
	ck_assert_int_eq(convert_to_decimal("CM"), 900);
}
END_TEST

START_TEST(test_convert_MMMCMXCIX_to_decimal_additional_coverage)
{
	ck_assert_int_eq(convert_to_decimal("MMMCMXCIX"), 3999);
}
END_TEST

START_TEST(test_convert_IM_Exits_with_1)
{
	convert_to_decimal("IM");
}
END_TEST

START_TEST(test_convert_XD_Exits_with_1)
{
	convert_to_decimal("XD");
}
END_TEST

START_TEST(test_value_larger_than_3999)
{
	convert_to_decimal("MMMM");
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
	tcase_add_exit_test(tc1_1, test_value_larger_than_3999, 2);
	tcase_add_exit_test(tc1_1, test_convert_IM_Exits_with_1, 1);
	tcase_add_exit_test(tc1_1, test_convert_XD_Exits_with_1, 1);
	tcase_add_exit_test(tc1_1, test_convert_MMMCMXCIX_to_decimal_additional_coverage, 0);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
