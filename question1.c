#include <stdio.h>
#include "question1.h"

void shift_element(int* arr, int i)
{
    for (int j = i; (arr+j) > arr; j = j -1)
    {
        *(arr+j) = *(arr+j-1);
    }

}

void insertion_sort(int* arr, int len)
{
    for (int i = 1; i < len; i++)
    {
        int counter = 0;
        int temp = *(arr + i);
        int j = i - 1;
        for (; (j >= 0) && (*(arr + j) > *(arr + i)); j = j - 1)
        {
            counter++;
        }
        shift_element(arr + j + 1, counter);
        *(arr+j+1)= temp;
    }
}

void print_array (int* arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        printf("%d,",*(arr + i));
    }
    printf("%d", *(arr+len-1));
    
}

int main()
{
    int arr[50];
    for (int i = 0; i < 50; i++)
    {
        scanf("%d",(arr + i));
    }
    
    insertion_sort(arr, 50);
    print_array(arr, 50);
}