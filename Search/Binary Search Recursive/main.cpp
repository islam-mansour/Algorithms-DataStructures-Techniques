#include <iostream>
using namespace std;

int A[] = {1,3,6,5,44,77,102,225,698};

int binSearch(int key, int l,int r){

    if(l > r)
        return -1;

    int mid = (l+r)/2;

    if(A[mid] == key)
        return mid;

    if(A[mid] > key)
        return binSearch(key, l, mid-1);
    else
        return binSearch(key, mid+1, r);

}

int main()
{

    cout << binSearch(44, 0, 8) << '\n';

    return 0;
}
