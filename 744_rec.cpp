#include <fstream>
using namespace std;
ifstream in("rec.in");
ofstream out("rec.out");
///https://www.pbinfo.ro/probleme/744/rec
///https://www.pbinfo.ro/detalii-evaluare/51580313
///dp[i] = nr modalitati de a impartii premile
int64_t s, n, f, dp[402];
int main(){
    in>>s>>n>>f; s -= n * f;
    for(int i = 0; i <= s; i++) dp[i] = 1;
    for(int i = 2; i <= n; i += 1)
        for(int j = i; j <= s; j += 1)
            dp[j] += dp[j - i];
    out<<dp[s];
    return 0;
}
