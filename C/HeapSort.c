

/*void HeapSortPsoudo(int *arr, size_t size)*/

    /* Heapify: */
    /* traverse all the array in loop till size */
    /* each iterate preform "HeapDown"/"BobbleDown"*/
    
    /* Starting with the index 0, which now is the root and the max value */
    /* Swap between the index 0
    and the last element which is size of the array - 1 */
    /* HeapDown index 0 which is the new element */
    /* Swap between the index 0 and the 
    new last element which is size of the array - 2 */
    /* do this process till last element index equal to the first element */
    
    
#include <stddef.h>


void HeapDown(int *arr, int size, int i);
void HeapSort(int *arr, size_t size);

void HeapSort(int *arr, size_t size)
{
    int i = 0;
    /* Build max heap from the array: */
    for ( i = size / 2 - 1; i >= 0; i--) {
        HeapDown(arr, size, i);
    }
    
    /* Sort the array: */
    for ( i = size - 1; i > 0; i--) {
        /* Swap the root (max element) with the last element: */
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        /* Restore the heap property by heapifying the root: */
        HeapDown(arr, i, 0);
    }
}

/* HeapDown (also called "sift down" or "bubble down") the element at index i in the heap: */
void HeapDown(int *arr, int size, int i) {
    int largest = i; /* Initialize largest as root */
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    /* Find the largest element among the root, left child, and right child: */
    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }
    
    /* If the largest element is not the root, swap it with the root and HeapDown the affected subtree: */
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        HeapDown(arr, size, largest);
    }
}

int main()
{
    int arr[10]= {1,3,0,2,4,5,6,7,9,8};
    int i = 0;
    HeapSort(arr, 10);
    
    
    for (i = 0; i < 10; ++i)
    {
        printf(" %d ", arr[i]);
    }
    
    
    
    return 0;
}
