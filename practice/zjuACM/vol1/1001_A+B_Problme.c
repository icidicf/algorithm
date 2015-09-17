#include<stdio.h>

/*
   two way to run this 
   1, ./a.out and input A and B manully
   2, ./a.out  < input > output
   */
void main()
{
    int A,B;
    while(scanf("%d%d",&A,&B)!=EOF)
    {
        printf("%d\n",A+B);
    }
}
