/*
This is a simple driver program for roman calculator libaray
This is a menu driven program provides the operability of a roman calculator
Also provides informative messages on invalid inputs
*/



#include<stdio.h>
#include "roman_ops.h"

int main(){

	
    int choice,num1,num2;
	char str[ARRAY_SZ],str2[ARRAY_SZ],str3[ARRAY_SZ];
	while(1){

        printf("\n##########RomanCalculator#########\n");
        printf("\nSelect Operations\n1.Addition.\n2.Subtraction.\n3.Exit.\n");
        scanf("%d",&choice);
        if(choice==3) break;
        else{
            printf("Please enter first operand:");scanf("%s",str);
            printf("Please enter second operand:");scanf("%s",str2);
            num1 = toDec(str);
            num2 = toDec(str2);
            
			if(num1>3999 || num2>3999)  {printf("\nBAD INPUT - One or both of inputs exceed valid upper limit of roman numerals\n");continue;}

			
			if(choice==1){
            	if(num1+num2>3999) {printf("\nBAD INPUT - Result exceeds valid upper limit of roman numerals\n");continue;}
			    toRoman(str3,num1+num2);
                printf("Addition result: %s\n",str3);
            }
            else if(choice==2){
                if(num1-num2>=1){
                    toRoman(str3,num1-num2);
                    printf("Subtraction result: %s\n",str3);
                }
                else printf("\nBAD INPUT - Subtraction not possible!\n");
            }
			else continue;

        }
    }
	return 0;
}

