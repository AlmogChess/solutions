
1. Given three integer variables, x = 512, y = 1024, and z = 2048, write a program
to print out their left values as well as their right values.

#include <stdio.h>

int main()
{
    
    int x = 512;
    int y = 1024;
    int z = 204;
    

    printf("the right value of x is %d and the left value is %p \n", x, &x);
    printf("the right value of x is %d and the left value is %p \n", y, &y);
    printf("the right value of x is %d and the left value is %p", z, &z);

    return 0;
}


2. Write a program to update the value of the double variable flt_num from 123.45
to 543.21 by using a double pointer.

#include <stdio.h>

int main()
{
    
double fit_num = 123.45;

printf("the value of fit_num is %f \n" ,fit_num);

double *ptr = &fit_num;

*ptr = 543.21;

printf("the value of fit_num is %f \n" ,fit_num);

    return 0;
}


3.Given a character variable ch and ch = ‘A’, write a program to update the value of
ch to decimal 66 by using a pointer


4. Given that x=5 and y=6, write a program to calculate the multiplication of the two
integers and print out the result, which is saved in x, all in the way of indirection
(that is, using pointers).

#include <stdio.h>

int main()
{
    int x = 5;
    int y = 6;
    int *ptrX = &x;
    
    printf("x = %d , and y = %d, x times y = %d \n" ,x, y, x * y);
    *ptrX = x * y;
    printf("new x = %d" ,x);

}


Q How do you reference an array by using a pointer?
A You can use a pointer to reference an array by assigning the start address of an
array to the pointer. For example, given a pointer variable ptr_ch and a character
array array_ch, you can use one of the following statements to reference the array
by the pointer:
ptr_ch = array_ch;
or
ptr_ch = &array_ch[0];




1. Given this character array:
char array_ch[5] = {‘A’, ‘B’, ‘C’, ‘D’, ‘E’};

#include <stdio.h>

int main()
{
    
char ch[5] = {'A', 'B', 'C', 'D', 'E'};

    printf("%c %c %c %c %c \n" , ch[0],ch[1],ch[2],ch[3],ch[4]);


}

2. Rewrite the program in Exercise 1, but this time use a for loop to initialize the
character array with ‘a’, ‘b’, ‘c’, ‘d’, and ‘e’, and then print out the value of
each element in the array.

#include <stdio.h>

int main()
{
    
char ch[5] = {'A', 'B', 'C', 'D', 'E'};


for(int i = 0;i <5; i++)
{
    
    printf("%c\n" , ch[i]);

}


}



3. Given this two-dimensional unsized array:
char list_ch[][2] = {
‘1’, ‘a’,
‘2’, ‘b’,
‘3’, ‘c’,
‘4’, ‘d’,
‘5’, ‘e’,
‘6’, ‘f’};
write a program to measure the total bytes taken by the array, and then print out all
elements of the array

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    
char list_ch[][2] = {
'1', 'a',
'2', 'b',
'3', 'c',
'4', 'd',
'5', 'e',
'6', 'f'};

int x = sizeof(list_ch);

    printf("the size of the array is : %d byte\n" , x);
    
int y = sizeof(char);

    printf("check : the size of the array is : %d byte \n" , y * 6 * 2);


for(int j = 0;j <2; j++)
{
for(int i = 0;i <6; i++)
{
    
    printf("%c\n" , list_ch[i][j]);

}

}

}



