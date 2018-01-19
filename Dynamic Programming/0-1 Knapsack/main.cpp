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
            return -1000;
        else
            return 0;
    }


    if(Memo[i][W] != -1)
        return Memo[i][W];


    return Memo[i][W] = max(solve(i+1, W), Value[i]+solve(i+1, W-Weight[i]));


}


int main()
{


    initMemo();

    cout << solve(0, W) << '\n';


    return 0;
}
