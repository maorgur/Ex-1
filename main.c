#include <stdio.h>
#include "NumClass.h"
//#include "basicClassifcation.c"
//#include "advancedClassificationLoop.c"
//#include "advancedClassificationRecursion.c"

int main() { 

    //initialize variables
    int num1 = 0; 
    int num2 = 0;

    //read from input
    
    scanf("%d", &num1);
    scanf("%d", &num2);

    printf("The Armstrong numbers are:");
    for (int i = num1; i <= num2; i++){
        if (isArmstrong(i)){
            printf(" %d", i);
        }
    }

    printf("\nThe Palindromes are:");
    for (int i = num1; i <= num2; i++){
        if (isPalindrome(i)){
            printf(" %d", i);
        }
    }

    printf("\nThe Prime numbers are:");
    for (int i = num1; i <= num2; i++){
        if (isPrime(i)){
            printf(" %d", i);
        }
    }

    printf("\nThe Strong numbers are:");
    for (int i = num1; i <= num2; i++){
        if (isStrong(i)){
            printf(" %d", i);
        }
    }
    printf("\n"); //in the example output files there are an extra line
    return 0;
}