#include <iostream>
#include <math.h>

using namespace std;

const int n = 5;
const int W = 50;

double Weight[] = {1.6, 2.9, 5.7, 11.2, 7.4};
double Value[]  = {2.0, 6.2, 4.3, 47.3, 2.5};

double Memo[n][W+1];

void initMemo(){
    for(int i=0; i<n; ++i)
        for(int j=0; j<=W; ++j)
            Memo[i][j] = -1;
}

double solve(int i, int W){

    if(W == 0)
        return 0;

    if(i == n){
        if(W < 0)
            return (double)-1e9;
        else
            return 0;
    }

    if(Memo[i][W] != -1)
        return Memo[i][W];

    double c1, c2=0;

    c1 = solve(i+1, W);

    while( (W-Weight[i]) >= 0){

       c2 += Value[i] + solve(i+1, W-Weight[i]);

       W -= Weight[i];

    }

    return Memo[i][W] = max(c1, c2);

}

int main()
{

    initMemo();

    cout << solve(0, W) << '\n';

    return 0;
}
