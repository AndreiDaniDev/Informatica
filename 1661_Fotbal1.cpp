#include <iostream>
using namespace std;
///Numar De Drumuri in Matrice ((1, 1) -> (n, m))
///https://www.pbinfo.ro/probleme/1661/fotbal1
///https://www.pbinfo.ro/probleme/1661/fotbal1
int n, m, bit1, bit2; int64_t dp[2][10002];
int main(){
  	cin>>n>>m; 
   
    dp[0][0] = 1; dp[1][0] = 1;
    for(int j = 1; j <= m; j++)
        dp[0][j] = 1;
    
    for(int i = 1; i <= n; i++){
        bit1 = (i & 1); bit2 = (i - 1) & 1;
        for(int j = 1; j <= m; j++)
            dp[bit1][j] = dp[bit2][j] + dp[bit1][j - 1];
    }
    
    cout<<dp[bit1][m];
    return 0;
}
