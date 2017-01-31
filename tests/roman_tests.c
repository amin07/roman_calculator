#include<stdio.h>
#include<check.h>

START_TEST(test_dec_of_roman_digit)
{
    ck_assert_int_eq(retDec('V'),5);
}
END_TEST

Suite *roman_test_suite(){

    Suite *s;
    TCase *test_case;
    test_case = tcase_create("Head case");
    s = suite_create("Roman test suite");

    tcase_add_test(test_case, test_addition);
    suite_add_tcase(s, test_case);

    return s;

}


int main(){
	
	Suite *s = roman_test_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr,CK_NORMAL);
	return 0;
}

