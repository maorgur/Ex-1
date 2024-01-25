#include "NumClass.h"
#define TRUE 1
#define FALSE 0

int power(int num1, int num2){
    if (num1 * num2 == 0) {return 0;}

    int sum = num1;
    for (int i = 1; i < num2; i++){
        sum = sum * num1;
    }
    return sum;
}

int lenOfNum(int num){
    //check the length of a number
    int divider = 10;
    int length = 1;
    while ((int)( num / divider) > 0){
        divider = divider * 10;
        length++;
    }
    return length;
}

int isArmstrong(int num){
    int sum = 0;
    int powerNum = lenOfNum(num);
    int rest = num;

    while (rest > 0){
        //first, get the last digit using % operator
        //add the factorial of this number to sum and divide rest by 10

        if (rest % 10 > 0) {
            sum += power(rest % 10, powerNum);
        }
        //divide rest
        rest = rest / 10;

    }


    return (sum == num);
}


int isPalindrome(int num){
    int reversed = 0;
    int numLen = lenOfNum(num);
    int rest = num;

    while (rest > 0){
        //first, get the last digit using % operator
        //add the factorial of this number to sum and divide rest by 10

        if (rest % 10 > 0) {
            reversed += power(10, numLen) * (rest % 10);
        }
        //divide rest
        rest = rest / 10;
        numLen --;

    }
    if (reversed / 10 == num){
        return TRUE;
    } else {
        return FALSE;
    }
}
