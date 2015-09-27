#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 255
/*
   key point 
   keep the num represent internal start with 0
   so need reverse the input when read s1 and s2
*/
void printBigNum(char result[])
{
    int i;
    int len = MAX_NUM;
    i = len-1;
    while((i > 0) && (result[--i] == 0));
    for (; i >= 0 ; i--)
        putchar(result[i] + '0');

    putchar('\n');

}

int add(char s1[], char s2[], char result[])
{

    int i,j;
    int len1 = strlen(s1) ;
    int len2 = strlen(s2) ;
    int resultLen = MAX_NUM;
    int isOverflow = 0, takeOver = 0;
    unsigned char *num1 = malloc(sizeof(unsigned char) * (MAX_NUM+1));
    unsigned char *num2 = malloc(sizeof(unsigned char) * (MAX_NUM+1));


    for (i = len1 - 1, j = 0; (i >= 0) && (i < resultLen) ; i--, j++)
        num1[j] = s1[i] - '0' ;


    for (i = len2 - 1, j = 0; (i >= 0) && (i < resultLen); i--, j++ )
        num2[j] = s2[i] - '0' ;

    for (i = 0 ; i < resultLen; i++) {
        if ((result[i] = num1[i] + num2[i] + takeOver ) > 9 ) {
            result[i] -= 10;
            takeOver = 1;
        } else {
            takeOver = 0;
        }
    }

    if (result[resultLen] > 0)
        isOverflow = 1;

    return isOverflow;
}

int main(void)
{
    unsigned char result[256];
    memset(result ,0 , 256);
    unsigned char *num1="123456789525";
    unsigned char *num2="852741963753951";

    long long n1=123456789525;
    long long  n2=852741963753951;
    if (!add(num1, num2, result)) {
        printf("go to print, true reuslt is %lld\n", n1+n2);
        printBigNum(result);
    } else {
        printf("over flow happen\n");
    }

    return 0;
}
