#include <fstream>
using namespace std;
ifstream in("sumtri.in");
ofstream out("sumtri.out");

///https://www.pbinfo.ro/probleme/385/sumtri
///https://www.pbinfo.ro/detalii-evaluare/51571913

/*
dp[i][j] = costul maxim de la (1, 1) la (i, j), in triunghi
dp[i][j] = dp[i][j] + max( dp[i - 1][j], dp[i - 1][j - 1] )
*/

int n, dp[101][101], maxi;
int main(){
    in >> n;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= i ; j++)
            in >> dp[i][j];
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= i ; j++)
            dp[i][j] += max( dp[i - 1][j] , dp[i - 1][j - 1] );
    for(int i = 1 ; i <= n ; i++)
        maxi = max( dp[n][i] , maxi );
    out << maxi;
    return 0;
}
