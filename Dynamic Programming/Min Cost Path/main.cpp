#include <iostream>

using namespace std;

const int n = 3, m = 3;

int Memo[n][m];
int initMemo(){
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            Memo[i][j] = -1;
}

int Map[n][m] = {
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3}
    };

bool ok(int i,int j){
    return (i>=0&&i<n && j>=0&&j<m);
}

int solve(int i,int j){

    if(!ok(i,j))
        return 100000;

    if(i == n-1 && j == m-1)
        return Map[i][j];

    if(Memo[i][j] != -1)
        return Memo[i][j];

    return Memo[i][j] = Map[i][j] + min(solve(i+1, j+1), min(solve(i, j+1), solve(i+1, j)));

}

int main()
{

    initMemo();

    cout << solve(0, 0) << '\n';

    return 0;
}
