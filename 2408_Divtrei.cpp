#include <fstream>
using namespace std;
ifstream in("divtrei.in");
ofstream out("divtrei.out");
///https://www.pbinfo.ro/probleme/2408/divtrei
///https://www.pbinfo.ro/detalii-evaluare/51650501
int n, k, x, r[4], dp[8];
int main(){
    in>>n>>k;
    for(int i = 1; i <= n; i++)
        in>>x, r[x % 3] += 1;
    dp[0] = r[0]; dp[1] = r[1]; dp[2] = r[2];
    for(int i = 1; i < k; i++){
        if(r[0] > 0){
            dp[3] += r[0] * dp[0];
            dp[4] += r[0] * dp[1];
            dp[5] += r[0] * dp[2];
        }
        if(r[1] > 0){
            dp[3] += r[1] * dp[2];
            dp[4] += r[1] * dp[0];
            dp[5] += r[1] * dp[1];
        }
        if(r[2] > 0){
            dp[3] += r[2] * dp[1];
            dp[4] += r[2] * dp[2];
            dp[5] += r[2] * dp[0];
        }
        dp[0] = dp[3] % 4001;
        dp[1] = dp[4] % 4001;
        dp[2] = dp[5] % 4001;
        dp[3] = 0;
        dp[4] = 0;
        dp[5] = 0;
    }
    out<<dp[0];
    return 0;
}
