#include "NumClass.h"
#define TRUE 1
#define FALSE 0

int isPrime(int num){
    if (num < 1){return FALSE;} //https://www.google.com/search?q=are+negative+numbers+prime

    for (int i = 2; i < num; i++){ //loop over all the numbers a
        if (num % i == 0){
            return FALSE;
        }
    }

    return TRUE;
}

int factorial(int num){
    // a function for isStrong to calculate the factorial of a number
    int sum = 1;
    for (int i = 1; i <= num; i++){
        sum = sum * i;
    }
    return sum;
}


int isStrong(int num){
    int sum = 0;
    int rest = num;

    while (rest > 0){
        //first, get the last digit using % operator
        //add the factorial of this number to sum and divide rest by 10

        sum += factorial(rest % 10);
        //divide rest
        rest = rest / 10;

    }

    return sum == num;
}