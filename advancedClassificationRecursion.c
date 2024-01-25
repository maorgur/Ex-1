#include "NumClass.h"
#define TRUE 1
#define FALSE 0


//recursive
int RecPower(int num1, int num2){
    if ((num1 * num2) == 0) {return 0;}
    if (num2 == 1){return num1;}
    return RecPower(num1, num2 - 1) * num1;
}

int RecLenOfNum(int num){
    //check the length of a number
    if (num < 10){return 1;}
    return (1 + RecLenOfNum(num / 10));
}

int isArmstrong(int num){
    int num_len = RecLenOfNum(num);
    int sum = ArmstrongValue(num, num_len);
    if (sum == num){
        return TRUE;
    } else {
        return FALSE;
    }
}

int ArmstrongValue(int num, int num_len){
    if (num < 10){
        return RecPower(num, num_len);
    } else {
        return (RecPower(num % 10, num_len) + ArmstrongValue(num / 10, num_len));
    }
}

int isPalindrome(int num){
    //take the first and last numbers and compare them and recursive the rest
    if (num < 10) { //1 digit
        return TRUE;
    }
    int digitsCount = RecLenOfNum(num);
    int last_num = num % 10;
    int first_num = num / (RecPower(10, digitsCount)/10);

    int middle = num;
    middle -= first_num * (RecPower(10, digitsCount)/10);
    middle = middle / 10;
    if (first_num != last_num) {
        return FALSE;
    } else if (digitsCount - RecLenOfNum(middle) > 2){
        //there are leading zeros, some checks to see it's fine:
        int leading_zeroes = digitsCount - RecLenOfNum(middle) - 2;
        //check if there are the same amount of trailing zeroes
        if (((middle / (RecPower(10, leading_zeroes))) * RecPower(10, leading_zeroes)) == middle){ //number is the same even after rounding it
            //check the palindrome without the zeroes in both sides
            return isPalindrome(middle / (RecPower(10, leading_zeroes)));
        } else {
            return FALSE; //there are zeroes at the start, but not at the end
        }
    } else {
        return isPalindrome(middle);
    }
}
