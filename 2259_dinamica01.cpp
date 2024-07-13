#include <iostream>
using namespace std;
int n, dp[2][100001];

///https://www.pbinfo.ro/probleme/2259/dinamica01
///https://www.pbinfo.ro/detalii-evaluare/51571303

/*
dp[0][i] + dp[1][i] = raspuns pentru n cifre
dp[0][i] = (daca i == 1) -> 4 altfel 4 * dp[1][i - 1] 
dp[1][i] = (daca i == 1) -> 5 altfel 5 * dp[0][i - 1]

dp[0][1] = 4 deoarece numerele sunt 2, 4, 6, 8
dp[1][1] = 5 deoarece numerele sunt 1, 3, 5, 7, 9
*/

int main(){
    cin >> n; dp[0][1] = 4; dp[1][1] = 5;
    for (int i = 2; i <= n; i++){
        dp[0][i] = (4 * dp[1][i - 1]) % 30103;
        dp[1][i] = (5 * dp[0][i - 1]) % 30103;
    }
    cout << (dp[0][n] + dp[1][n]) % 30103;
    return 0;
}
