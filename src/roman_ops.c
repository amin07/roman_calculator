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



