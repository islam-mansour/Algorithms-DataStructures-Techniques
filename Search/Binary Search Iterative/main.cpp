#include <iostream>
using namespace std;

int A[] = {2,4,6,8,11,65,123,222,542};

int binSearch(int key){

    int l=0, r=8;

    while(l<=r){

        int mid = (l+r)/2;

        if(A[mid] == key)
            return mid;

        if(A[mid] > key){
            r = mid - 1;
        } else {
            l = mid + 1;
        }

    }

    return -1;

}

int main()
{

    cout << binSearch(222) << endl;

    return 0;
}
