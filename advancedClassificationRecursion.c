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
    } else if (middle < 10 && middle > 0 && digitsCount == 4){
        return FALSE; //edge case when the middle is 01 - 09 (not 1-9), like 1051
    } else {
        return isPalindrome(middle);
    }
}
