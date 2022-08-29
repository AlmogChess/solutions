#include <stdio.h>
#include <stdlib.h>


int Factorial(int num){
    int sum = 1;
    for (int i = 0 ; i<num; i++)
    {
        sum = sum * (num * ( num - 1));
        num = num - 2;
    }
    return sum;

}


int main()
{
    printf("%d", Factorial(5));

    return 0;



}

