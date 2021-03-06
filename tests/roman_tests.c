#include<stdio.h>
#include<check.h>
#include "roman_ops.h"


/*
This blocks contains all tests related to a helper function which is
required for successful conversion between roman and decimals
*/
START_TEST(test_dec_of_roman_digit)
{
    ck_assert_int_eq(retDec('V'),5);
    ck_assert_int_eq(retDec('v'),5);
    ck_assert_int_eq(retDec('i'),1);
    ck_assert_int_eq(retDec('x'),10);
}
END_TEST

/*
This blocks contains all tests related to decimal to roman conversion
*/

START_TEST(test_dec_to_roman_conversion)
{
    char str[ARRAY_SZ];
    toRoman(str,1);
    ck_assert_str_eq(str,"I");
	toRoman(str,3999);
    ck_assert_str_eq(str,"MMMCMXCIX");
    toRoman(str,3888);
	ck_assert_str_eq(str,"MMMDCCCLXXXVIII");
	toRoman(str,3231);
	ck_assert_str_eq(str,"MMMCCXXXI");
	toRoman(str,231);
	ck_assert_str_eq(str,"CCXXXI");
	toRoman(str,55);
	ck_assert_str_eq(str,"LV");
}
END_TEST

/*
This blocks contains all tests related to roman to decimal conversion
*/
START_TEST(test_roman_to_dec_conversion)
{
    ck_assert_int_eq(1,toDec("I"));
    ck_assert_int_eq(3999,toDec("MMMCMXCIX"));
	ck_assert_int_eq(3888,toDec("MMMDCCCLXXXVIII"));
	ck_assert_int_eq(421,toDec("CDXXI"));
	ck_assert_int_eq(333,toDec("CCCXXXIII"));
	ck_assert_int_eq(66,toDec("LXVI"));
	ck_assert_int_eq(494,toDec("CDXCIV"));
}
END_TEST


/*
This blocks contains all tests related to addition
*/
START_TEST(test_addition)
{
	char *str1;
	char *str2;
	char res[ARRAY_SZ];
	
	str1 = "I";
	str2 = "D";
    toRoman(res,toDec(str1)+toDec(str2));
    ck_assert_str_eq(res,"DI");
	
	str1 = "CD";
	str2 = "XCIV";	
    toRoman(res,toDec(str1)+toDec(str2));
    ck_assert_str_eq(res,"CDXCIV");

	str1 = "DXXIII";			//523
	str2 = "CCCXXIII";			//323
    toRoman(res,toDec(str1)+toDec(str2));
    ck_assert_str_eq(res,"DCCCXLVI");

	str1 = "I";					// 1
	str2 = "MMMCMXCVIII";		// 3998
    toRoman(res,toDec(str1)+toDec(str2));
    ck_assert_str_eq(res,"MMMCMXCIX");

	
	str1 = "MMDLV";				//2555
	str2 = "IV";				//4	
    toRoman(res,toDec(str1)+toDec(str2));
    ck_assert_str_eq(res,"MMDLIX");

}
END_TEST


/*
This blocks contains all tests related to subtraction
*/

START_TEST(test_subtraction)
{
	char *str1;
	char *str2;
	char res[ARRAY_SZ];
	
	str1 = "D";
	str2 = "I";
    toRoman(res,toDec(str1)-toDec(str2));
    ck_assert_str_eq(res,"CDXCIX");
	
	
	str1 = "CDIV";
	str2 = "CDI";	
    toRoman(res,toDec(str1)-toDec(str2));
    ck_assert_str_eq(res,"III");

	str1 = "DCCCXXVII";			//827
	str2 = "CDXCIV";			//494
    toRoman(res,toDec(str1)-toDec(str2));
    ck_assert_str_eq(res,"CCCXXXIII");

	str1 = "MMMDCCCLXXX";		// 3880
	str2 = "DCCLIII";			// 753
    toRoman(res,toDec(str1)-toDec(str2));
    ck_assert_str_eq(res,"MMMCXXVII");

	
	str1 = "LXXIX";				//79
	str2 = "XL";				//40	
    toRoman(res,toDec(str1)-toDec(str2));
    ck_assert_str_eq(res,"XXXIX");
	

}
END_TEST

/*
This function creates a test suite with all the test cases we wrote earlier
and returns it to main so that we can see the outputs of test runs
*/

Suite *roman_test_suite(){

    Suite *s;
    TCase *test_case;
    test_case = tcase_create("Head case");
    s = suite_create("Roman test suite");

    tcase_add_test(test_case, test_dec_of_roman_digit);
    tcase_add_test(test_case, test_dec_to_roman_conversion);
    tcase_add_test(test_case, test_roman_to_dec_conversion);
    
    tcase_add_test(test_case, test_addition);
    tcase_add_test(test_case, test_subtraction);
	suite_add_tcase(s, test_case);

    return s;

}


int main(){
	
	Suite *s = roman_test_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr,CK_NORMAL);
	return 0;
}

