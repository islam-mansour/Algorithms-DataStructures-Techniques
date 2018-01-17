#include <iostream>
#include <random>
#include <time.h>

/* the array, low, high  => nothing */
void mergeSort(int [], int, int);

/* the array, low, high, middle  => nothing */
void merge(int [], int, int, int);

/* the array, its size  => nothing */
void printArray(int [], int);

/* the size, lowest value, highest value  => Array with random integers in the range --including lowest and highest-- */
int* generateRandomArray(int, int, int);

using namespace std;

int main()
{
    int Size, low, high;
    Size = 10;
    int* x;
    low = -100;
    high = 100;

    x = generateRandomArray(Size, low, high);
    printArray(x, Size);
    mergeSort(x, 0, Size-1);
    printArray(x, Size);
    delete x;

    return 0;
}

/* merge sort functions */
void mergeSort(int arr[], int L, int R){
    if(R <= L){
        return;
    }
    int middle = L+(R-L)/2;
    mergeSort(arr, L, middle);
    mergeSort(arr, middle+1, R);
    merge(arr, L, middle, R);
}

void merge(int arr[], int l, int m, int r){
    /*  The Size of new arrays  */
    int s1, s2;
    s1 = m - l + 1;
    s2 = r - m;

    /* create new Arrays */
    int *L = new int[s1], *R = new int[s2];

    /* fill our arrays */
    for(int temp=0; temp<s1; ++temp){
        L[temp] = arr[l + temp];
    }
    for(int temp=0; temp<s2; ++temp){
        R[temp] = arr[m + 1 + temp];
    }

    int i=0, j=0, k=l;   // one index for every array     i => L, j => R, k => arr

    /* merge the arrays into the main array */
    while(i < s1 && j < s2){
        if(L[i] < R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }
    while(i < s1){
        arr[k++] = L[i++];
    }
    while(j < s2){
        arr[k++] = R[j++];
    }
    delete L, R;
}

/* to Print an array */
void printArray(int arr[], int Size){
    for(int i=0; i<Size-1; ++i){
        cout<<arr[i]<<", ";
    }
    cout<<arr[Size-1]<<endl;
}

/* to generate random Array */
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
