#include <fstream>
using namespace std;
ifstream in("cladire3.in");
ofstream out("cladire3.out");
int n, m, dp[204][204];

///https://www.pbinfo.ro/probleme/433/cladire3
///https://www.pbinfo.ro/detalii-evaluare/51571898

/*
dp[i][j] = costul minim de la (n, 1) la (i, j), daca este posibil
dp[i][j] = dp[i][j] + min( dp[i + 1][j], dp[i][j - 1] )
*/

int main(){
	in>>n>>m;
    
    for(int i = 0; i <= n; i++) dp[i][0] = (1 << 30);
    for(int i = 0; i <= m; i++) dp[n + 1][i] = (1 << 30);
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        	in>>dp[i][j];
        
    for(int i = n; i >= 1; i--)
        for(int j = 1; j <= m; j++)
        	dp[i][j] += (min(dp[i + 1][j], dp[i][j - 1]) * (i != n  || j != 1));
    
    out<<dp[1][m];
    return 0;
}
