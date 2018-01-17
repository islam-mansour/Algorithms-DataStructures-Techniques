#include <iostream>
#include <vector>
using namespace std;


void Sort(vector<int> &arr, int sz){

    for(int i=0; i<sz; ++i){

        for(int j=0; j<sz-i-1; ++j){

            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);

        }

    }

}


int main()
{

    cout << "Enter Size of the Array: ";
    int sz;
    cin >> sz;

    vector<int> arr(sz);

    cout << "Enter the Elements of the Array : ";
    for(int i=0; i<sz; i++)
        cin >> arr[i];

    // O(n^2)
    Sort(arr, sz);

    cout << "Elements After Sorting : ";
    for(int i=0; i<sz; i++)
        cout << arr[i] << " ";
    cout << '\n';


    return 0;
}
