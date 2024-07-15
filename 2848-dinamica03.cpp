#include <iostream>
using namespace std;

///https://www.pbinfo.ro/probleme/2848/dinamica03
///https://www.pbinfo.ro/detalii-evaluare/51579674

/*

dp[0][i] + dp[1][i] = nr cuvinte valide de lungime i
dp[0][i] = nr cuvinte care se termina in a / b
dp[1][i] = nr cuvinte care se termina in c / d

dp[0][i] = (dp[0][i - 1] + 2 * dp[1][i - 1]) 
/// a/b se pune la finalul orcarui cuvant care se termina cu a / b / c / d

dp[1][i] = 2 * (dp[0][i - 1] + dp[1][i - 1]) 
/// c/d se pune la finalul orcarui cuvant

*/

int n, dp[2][100002];
int main(){
    cin>>n; dp[0][1] = 2; dp[1][1] = 2;
    for(int i = 2; i <= n; i++){
        dp[0][i] = (dp[0][i - 1] + 2 * dp[1][i - 1]) % 777013;
        dp[1][i] = 2 * (dp[0][i - 1] + dp[1][i - 1]) % 777013;
    }
    cout<<(dp[0][n] + dp[1][n]) % 777013;
    return 0;
}
