#include <check.h>
#include "convert_decimal_to_roman.h"

START_TEST(test_convert_1000_to_roman)
{
  ck_assert_str_eq(convert(1), "M");
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *test_convert_decimal_to_roman = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, test_convert_decimal_to_roman);
    tcase_add_test(test_convert_decimal_to_roman, test_convert_1000_to_roman);
	
    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
