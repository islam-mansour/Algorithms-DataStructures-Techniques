#include <iostream>

using namespace std;

const int m = 5;
int Coins[m] = {1, 5, 10 , 20, 50};

int Memo[m][1000000];
void initMemo(){
    for(int i=0; i<m; ++i)
        for(int j=0; j<1000000; ++j)
            Memo[i][j] = -1;
}

int solve(int i, int N){

    if(N == 0)
        return 1;

    if(i == m || N < 0)
        return 0;

    if(Memo[i][N] != -1)
        return Memo[i][N];

    return Memo[i][N] = solve(i+1, N-Coins[i]) + solve(i, N-Coins[i]);

}

int main()
{

    initMemo();

    cout << solve(0, 50) << '\n';


    return 0;
}
