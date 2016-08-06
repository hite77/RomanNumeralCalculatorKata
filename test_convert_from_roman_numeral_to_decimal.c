#include <check.h>
#include "convert_roman_to_decimal.h"

START_TEST(test_convert_I_to_decimal)
{
  char roman_one[] = "I";
  ck_assert_int_eq(convert(roman_one), 1);
}
END_TEST

START_TEST(test_convert_II_to_decimal)
{
   char roman_two[] = "II";
   ck_assert_int_eq(convert(roman_two), 2);
}
END_TEST

//Test for V so it knows that it is 5
//Also Test X=10, L=fifty, C=1 hundred, D=five hundred, and M =1000
//Test for IV should subtract one and be 4
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

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
