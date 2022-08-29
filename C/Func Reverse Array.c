#include <stdio.h>






void reverse(int Array[3]){
    int temp[3];
    int j = 2;
    for (int i = 0; i < 3; i++)
    {
        temp[j] = Array[i];
        j = j - 1;
    }
    for (int i = 0; i<3; i++)
    {
        Array[i] = temp[i];
    }
}




int main()

{
    int i, Array[3];
    printf(" Enter elements into the Array :n ");
    for (i=0; i< 3 ; i++)
    {
        printf("Enter %2d elements : ",i);
        scanf("%d",&Array[i]);
        printf("%d",Array[i]);
    }
    printf(" here is the new Array : ");

    reverse(Array);
    for (i=0; i< 3 ; i++)
    {
        printf("%d",Array[i]);
    }

    return 0;

}
