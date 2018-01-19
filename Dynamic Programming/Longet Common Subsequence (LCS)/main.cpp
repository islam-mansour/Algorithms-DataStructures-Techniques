#include <iostream>
#include <math.h>
using namespace std;

const int n = 6;

int A[] = {5, 6, 2, 1, 3, 11};
int B[] = {5, 1, 2, 1, 8, 3};

int Memo[n][n];

void initMemo(){
    for(int i=0; i<6; ++i)
        for(int j=0; j<6; ++j)
            Memo[i][j] = -1;
}

int solve(int i,int j){

    if(i == n || j == n)
        return 0;

    if(Memo[i][j] != -1)
        return Memo[i][j];

    if(A[i] == B[j])
        return Memo[i][j] = 1 + solve(i+1, j+1);

    return Memo[i][j] = max( solve(i+1, j), solve(i, j+1) );

}

int main()
{

    initMemo();

    cout << solve(0, 0) << '\n';

    return 0;
}
