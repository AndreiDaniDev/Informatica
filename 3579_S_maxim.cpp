#include <fstream>
using namespace std;
ifstream in("smax.in");
ofstream out("smax.out");

///https://www.pbinfo.ro/probleme/3579/s-maxim
///https://www.pbinfo.ro/detalii-evaluare/51571199

/*
dp[i] = suma maxima pana la elementul de pe pos i
dp[i] = max( dp[i - 1], dp[i - 2] + a[i] );
*/

int64_t n, a, dp[100002];
int main(){
	in>>n>>a; dp[1] = a;
    for(int i = 2; i <= n; i++)
        in>>a, dp[i] = max( dp[i - 1], dp[i - 2] + a);
    out<<dp[n];
    return 0;
}
