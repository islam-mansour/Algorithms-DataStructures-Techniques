#include <iostream>
#include <vector>
using namespace std;


void Sort(vector<int> &arr, int sz){

    for(int i=0; i<sz; ++i){

        int mnIndex = i;

        for(int j=i+1; j<sz; ++j){

            if(arr[j] < arr[mnIndex])
                mnIndex = j;

        }

        if(i != mnIndex)
            swap(arr[i], arr[mnIndex]);

    }

}


int main()
{

    cout << "Enter Size of the Array: ";
    int sz;
    cin >> sz;

    vector<int> arr(sz);

    cout << "Enter Elements of the Array: ";
    for(int i=0; i<sz; ++i)
        cin >> arr[i];

    // O(n^2)
    Sort(arr, sz);

    cout << "Elements After Sorting: ";
    for(int i=0; i<sz; ++i)
        cout << arr[i] << " ";
    cout << '\n';


    return 0;
}
