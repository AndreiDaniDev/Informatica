#include <fstream>
#include <string>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
///https://www.infoarena.ro/problema/cmlsc
///https://www.infoarena.ro/job_detail/3240051
int n, m, k, dp[1026][1026], a[1026], b[1026], c[1026];
int main(){
    in>>n>>m;
    for(int i = 1; i <= n; i++)
        in>>a[i];
    for(int j = 1; j <= m; j++)
        in>>b[j];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            dp[i][j] = ((a[i] == b[j]) ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]));
    }
    out<<dp[n][m]<<"\n";
    for(int i = n, j = m; i && j ; ){
        if(a[i] == b[j]){
            c[++k] = a[i], i--, j--;
        }else if(dp[i - 1][j] < dp[i][j - 1]){
            j--;
        }else{
            i--;
        }
    }
    for(; k; k--) out<<c[k]<<" ";
    return 0;
}
