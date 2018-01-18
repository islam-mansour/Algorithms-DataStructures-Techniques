#include <iostream>
#include <time.h>
#include <random>

/* the array, Size  => Sorted array */
int* CountSort(int [], int);

/* the array, its size  => nothing */
void printArray(int [], int);

/* the size, lowest value, highest value  => Array with random integers in the range --including lowest and highest-- */
int* generateRandomArray(int, int, int);

using namespace std;


int main()
{
    int *x, Size, low, high;
    Size = 10;
    low = -100;
    high = 100;
    x = generateRandomArray(Size, low, high);
    printArray(x, Size);
    x = CountSort(x, Size);
    printArray(x, Size);
    delete x;
    return 0;
}


/* to sort the array */
int* CountSort(int arr[], int Size){
    int *Count, *result, Max, shifting;
    shifting = Max = arr[0];
    /*
    Shifting array to make the smallest value = 0
    get the maximum number
    */

    for(int i=1; i<Size; ++i){
        if(Max<arr[i]) Max = arr[i];
        if(shifting>arr[i]) shifting = arr[i];
    }
    /* shifting */
    for(int i=0; i<Size; ++i){
        arr[i] -= shifting;
    }
    Max -= shifting;

    /* make array of zeros to count */
    Count = new int[Max+1];
    for(int i=0; i<=Max; ++i){
        Count[i] = 0;
    }

    for(int i=0; i<Size; ++i){
        Count[arr[i]]++;
    }

    for(int i=1; i<=Max; ++i){
        Count[i] += Count[i-1];
    }

    result = new int[Size];

    for(int i=0; i<Size; ++i){
        result[Count[arr[i]] -1] = arr[i];
        Count[arr[i]]--;
    }


    /* get the original data */
    for(int i=0; i<Size; ++i){
        result[i] += shifting;
    }

    delete Count;

    return result;
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
