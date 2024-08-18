#include <fstream>
#include <cmath>
using namespace std;
ifstream in("spatrat.in");
ofstream out("spatrat.out");
///https://www.pbinfo.ro/probleme/1092/spatrat
///https://www.pbinfo.ro/detalii-evaluare/51777451
int n, dp[100002], t[100002];
int main(){
    in>>n;
    for(int i = 1; i <= n; i++)
        dp[i] = (1 << 30), t[i] = (1 << 30);
    for(int i = sqrt(n); i >= 0; i--){
        for(int j = 0; j + i * i <= n; j++){
            if(dp[j + i * i] > dp[j] + 1)
                dp[j + i * i] = dp[j] + 1, t[j + i * i] = i;
        }
    }
    out<<dp[n]<<"\n";
    for(; n; ){
        out<<t[n]<<" ";
        n -= t[n] * t[n];
    }
    return 0;
}
