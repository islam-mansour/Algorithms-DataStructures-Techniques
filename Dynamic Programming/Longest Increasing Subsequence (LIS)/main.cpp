#include <iostream>
using namespace std;

const int n = 8;

int A[] = {5, 3, 6, 4, 8, 0, 32, 6};

int Memo[n][n];

void initMemo(){
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            Memo[i][j] = -1;
}

int solve(int i,int prev){

    if(i == n)
        return 0;

    if(Memo[i][prev] != -1)
        return Memo[i][prev];

    if(A[i] >= A[prev])
        return Memo[i][prev] = 1 + solve(i+1, i);

    return Memo[i][prev] = solve(i+1, prev);

}

int main()
{

    initMemo();

    cout << solve(0, 0) << '\n';

    return 0;
}
