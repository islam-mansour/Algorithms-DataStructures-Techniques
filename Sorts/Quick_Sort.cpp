#include <iostream>
#include <time.h>
#include <random>

int num = 0;

/* the array, start, end  => nothing */
void QuickSort(int [], int, int);

/* the array, its size  => nothing */
void printArray(int [], int);

/* the size, lowest value, highest value  => Array with random integers in the range --including lowest and highest-- */
int* generateRandomArray(int, int, int);

using namespace std;

int main()
{
    int *x, Size, low, high;
    Size = 100;
    low = -100;
    high = 100;
    x = generateRandomArray(Size, low, high);
    printArray(x, Size);
    QuickSort(x, 0, Size-1);
    printArray(x, Size);
    delete x;
    return 0;
}

/* to Print an array */
void printArray(int arr[], int Size){
    for(int i=0; i<Size-1; ++i){
        cout<<arr[i]<<", ";
    }
    cout<<arr[Size-1]<<endl;
}

/* to generate Array with random values */
int* generateRandomArray(int Size, int Low, int High){
    srand((int) time(0));
    int temp;
    int *Array = new int[Size];
    for(int i=0; i<Size; ++i){
        temp = Low + rand() % (High - Low + 1);
        Array[i] = temp;
    }
    return Array;
}

/* Sorting the array */
void QuickSort(int arr[], int l, int r){
    if(r <= l){
        return;
    }

    int pivot = arr[(int)(l+r)/2];
    int i = l, j=r;
    while(i<=j){
        while(arr[i] < pivot && i<=j){
            i++;
        }
        while(arr[j] > pivot && i<=j){
            j--;
        }
        if(i<=j){
            swap(arr[i++], arr[j--]);
        }
    }

    QuickSort(arr, l, j);
    QuickSort(arr, i, r);
}
