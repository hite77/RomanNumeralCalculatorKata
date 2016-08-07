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


//Also Test L=fifty, C=1 hundred, D=five hundred, and M =1000
//CM = 900
//no test cases should have more than one V,L, or D, or more than three I,X, or C
//MMMCMXCIX should be 3999

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

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
