#include <fstream>
#include <utility>
using namespace std;
ifstream in("materom.in");
ofstream out("materom.out");

///https://www.pbinfo.ro/probleme/2544/materom
///https://www.pbinfo.ro/detalii-evaluare/51603930
///https://kilonova.ro/submissions/405429

typedef pair <int, int> pii;
const int diffMax = 19 * 20;
int n, m, dp[22][2 * diffMax + 2], diff, summ; pii v[502];
int main(){
    in>>n>>m;
    for(int i = 1; i <= n; i++)
        in>>v[i].first>>v[i].second;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= 2 * diffMax; j++)
            dp[i][j] = (-(1 << 30));

    for(int i = 1; i <= n; i++){
        diff = v[i].first - v[i].second;
        summ = v[i].first + v[i].second;
        for(int j = min(i, m); j >= 2; j--){
            for(int k = (-20) * j + 20; k <= 20 * j - 20; k++)
                if(dp[j - 1][k + diffMax] != (-(1 << 30)))
                    dp[j][k + diff + diffMax] = max(dp[j][k + diff + diffMax], dp[j - 1][k + diffMax] + summ);
        }
        dp[1][diffMax + diff] = max(dp[1][diffMax + diff], summ);
    }
    for(int i = 0, op = 1; op; i++)
        if(dp[m][diffMax + i] != (-(1 << 30)) || dp[m][diffMax - i] != (-(1 << 30)))
            out<<i<<"\n"<<max(dp[m][diffMax + i], dp[m][diffMax - i]), op = 0;
    return 0;
}
