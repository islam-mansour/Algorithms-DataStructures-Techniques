#include <iostream>

using namespace std;

long long Memo[10000];

void initMemo(){
    for(int i=0; i<10000; ++i)
        Memo[i] = -1;
}

long long solve(int n){

    if(n <= 1)
        return n;

    if(Memo[n] != -1)
        return Memo[n];

    return Memo[n] = solve(n-1) + solve(n-2);

}

int main()
{

    initMemo();

    cout << solve(50) << '\n';

    return 0;
}
