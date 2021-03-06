#include <iostream>
#include <cstdlib>
#include <sys/time.h>
using namespace std;

void bubbleSort(int array[], int size);
int binarySearch_Iterative(int array[], int size, int key);

int main()
{
    int array[10];
    int n = sizeof(array)/sizeof(*array);

    srand(time(0));
    for(int i = 0 ; i < n ; i++)
        array[i] = 1 + (rand() % 10000);

    bubbleSort(array, n);

    int output = binarySearch_Iterative(array, n, 6);

    if(output == -1)
        cout<<endl<<"Key NOT found"<<endl;
    else
        cout<<endl<<"Key is found at "<<output<<endl;
}

void bubbleSort(int array[], int size)
{
    int temp = 0, flag = 0;

    // In each pass, the largest element in the unsorted part will bubble up to the highest index in the unsorted part.
    // After size-1 passes, list is sorted.
    for(int pass = 1 ; pass <= size-1 ; pass++)
    {
        int flag = 0;
        // No need to sort the sorted part of the array.
        // Also, value of i+1 should not be 'size' as it cannot be accessible. So, size-pass-1.
        for(int i = 0 ; i <= size-pass-1 ; i++)
            if(array[i] > array[i+1])
            {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                flag=1;
            }
        // If we go through a pass without swapping, then the list is already sorted.
        if(flag == 0) break;
    }
}

int binarySearch_Iterative(int array[], int size, int key)
{
    int low = 0, high = size-1;
    while(low <= high)
    {
        // low+high can exceed the maximum value that an integer can store
        int mid = low + (high - low)/2;
        if(key == array[mid])
            return mid;
        else if(key < array[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
