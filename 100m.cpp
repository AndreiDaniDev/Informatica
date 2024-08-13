#include <fstream>
using namespace std;
ifstream in("100m.in");
ofstream out("100m.out");
///https://www.infoarena.ro/problema/100m
///https://www.infoarena.ro/job_detail/3240291
int64_t n, s, p = 1, dp[2][5002];
int main(){
    in>>n; dp[0][0] = 1; dp[1][0] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= i; j++)
            dp[i & 1][j] = ((j + 1) * dp[(i - 1) & 1][j] + dp[(i - 1) & 1][j - 1]) % 666013;
    }
    for(int i = 1; i <= n; i++){
        s = (s + dp[(n - 1) & 1][i - 1] * p) % 666013;
        p = (p * (i + 1)) % 666013;
    }
    out<<s;
    return 0;
}
