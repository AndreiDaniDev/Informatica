#include <fstream>
using namespace std;
ifstream in("rucsac.in");
ofstream out("rucsac.out");
///https://infoarena.ro/problema/rucsac
///https://infoarena.ro/job_detail/3240058
int n, g, w[5002], p[5002], dp[2][10002];
int main(){
    in>>n>>g;
    for(int i = 1; i <= n; i++)
        in>>w[i]>>p[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= g; j++){
            if(w[i] <= j && p[i] + dp[(i - 1) & 1][j - w[i]] > dp[(i - 1) & 1][j])
                dp[i & 1][j] = p[i] + dp[(i - 1) & 1][j - w[i]]; else dp[i & 1][j] = dp[(i - 1) & 1][j];
        }
    }
    out<<dp[n & 1][g];
    return 0;
}
