#include<stdio.h>
#include<string.h>
#include "roman_ops.h"

// constants required for conversion process
const char *h[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
const char *t[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
const char *o[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};

/*
Helper function required for conversion
input: a character
returns: decimal equivalent to input character
*/
int retDec(char ch){

    if(ch=='i'||ch=='I') return 1;
    else if(ch=='v'||ch=='V') return 5;
    else if(ch=='x'||ch=='X') return 10;
    else if(ch=='l'||ch=='L') return 50;
    else if(ch=='c'||ch=='C') return 100;
    else if(ch=='d'||ch=='D') return 500;
    else if(ch=='m'||ch=='M') return 1000;
}


/*
This function is for conversion from decimal to roman
input: a string reference and a integer number
output: assign roman equivalent to integer to the string referenced passed
*/
void toRoman(char *str2, int num){
    strcpy(str2,"");
    int temp = num;
    int num_of_th = temp/1000;
    temp = temp%1000;
    while(num_of_th--) strcat(str2,"M");

    // adding hundred's place

    num_of_th = temp/100;
    temp = temp%100;
    strcat(str2,h[num_of_th]);

    // adding ten's place
    num_of_th = temp/10;
    temp = temp%10;
    strcat(str2,t[num_of_th]);

    // adding one's place
    strcat(str2,o[temp]);

}


/*
This function converts a roman number to an integer number
input: roman number as in a string reference
returns: integer equivalent of the roman number
*/
int toDec(char *str){
    int sum, i, j,len;
    sum = 0;
    len = strlen(str);
    for(i=0;i<len-1;i++){
        if(retDec(str[i])>retDec(str[i+1])){
            sum += retDec(str[i]);
            if(i+1==len-1) sum += retDec(str[i+1]);
        }
        else if(retDec(str[i])<retDec(str[i+1])){
            sum += (retDec(str[i+1])-retDec(str[i]));
            i++;
            if(i+1==len-1) sum += retDec(str[i+1]);
        }
        else if(i+2<len){
            if(retDec(str[i+1])==retDec(str[i+2])){
                sum += 3*retDec(str[i]);
                i+=2;
            }
            else{
                sum += 2*retDec(str[i]);
                i++;
            }
			if(i+1==len-1) sum += retDec(str[i+1]);
        }
        else{
            sum += 2*retDec(str[i]);
            i++;
        }

    }
    if(len==1) sum = retDec(str[0]);
    return sum;

}

