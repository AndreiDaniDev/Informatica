#include <fstream>
using namespace std;
ifstream in("pitic.in");
ofstream out("pitic.out");
/*
///https://www.pbinfo.ro/probleme/1824/pitic
///https://www.pbinfo.ro/detalii-evaluare/51579299
dp[i][j] = in cate moduri se pot ajunge din (1, 1) la (i, j)
dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]
*/
int64_t n, m, dp[52][52];
int main(){
    in>>n>>m; dp[1][1] = 1;
    for(int j = 1; j <= m; j++)
    	for(int i = 1; i <= n; i++)
        	dp[i][j] += dp[i - 1][j - 1] + dp[i][j - 1] + dp[i + 1][j - 1];
    out<<dp[1][m];
	return 0;
}
