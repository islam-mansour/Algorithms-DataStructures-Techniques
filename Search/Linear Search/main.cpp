#include <iostream>
using namespace std;

int A[] = {5,3,6,8,9,7,12,5};

int linearSearch(int key){ // O(n)

    for(int i=0; i<8; ++i){

        if(A[i] == key)
            return u;

    }

    return -1;

}

int main()
{

    cout << linearSearch(9) << '\n';

    cout << linearSearch(55) << '\n';

    return 0;
}
