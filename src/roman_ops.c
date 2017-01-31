#include<stdio.h>
#include "roman_ops.h"

int retDec(char ch){

    if(ch=='i'||ch=='I') return 1;
    else if(ch=='v'||ch=='V') return 5;
    else if(ch=='x'||ch=='X') return 10;
    else if(ch=='l'||ch=='L') return 50;
    else if(ch=='c'||ch=='C') return 100;
    else if(ch=='d'||ch=='D') return 500;
    else if(ch=='m'||ch=='M') return 1000;
}


void toRoman(char *str2, int num){
    strcpy(str2,"");
    //puts(h[2]);
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

