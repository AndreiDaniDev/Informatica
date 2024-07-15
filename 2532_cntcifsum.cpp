#include <iostream>
using namespace std;
///https://www.pbinfo.ro/probleme/2532/cntcifsum
///https://www.pbinfo.ro/detalii-evaluare/51578996
int n, k, dp[1002][9002];
int main(){
    cin>>n>>k;
    
    for(int i = 0; i <= 9; i++)
        dp[1][i] = 1;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++)
            if(dp[i][j])
                for(int t = 0; t <= 9; t++)
                    dp[i + 1][j + t] += dp[i][j], dp[i + 1][j + t] %= 666013;
    
    cout<<dp[n][k];
    return 0;
}
