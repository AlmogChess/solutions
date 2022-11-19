#include <stdio.h>

static void print(int x);

typedef struct print_me
{
   int x;
   void (*ptr_s)(int); 
}; 

static void print(int x)
{
   printf("%d",x);
}

int main () 
{
   int i = 0;
   int size = 10;
   struct print_me arr_print[10];

   for(i = 0; i < size; i++)
   {
      arr_print[i].x = i+1; 
      arr_print[i].ptr_s = &print;
   }
   for(i = 0; i < size; i++)
   {
      arr_print[i].ptr_s(arr_print[i].x);
   }
}
