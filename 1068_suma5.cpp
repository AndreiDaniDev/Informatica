#include <fstream>
using namespace std;
ifstream in("suma5.in");
ofstream out("suma5.out");
const int dpSIZE = 63, costMax = (1 << 30) - 1 + (1 << 30);
int n, x, y, z = 1, dp[dpSIZE + 2][dpSIZE + 2][dpSIZE + 2], cost = costMax;

///https://www.pbinfo.ro/probleme/1068/suma5
///https://www.pbinfo.ro/detalii-evaluare/51582692
///https://kilonova.ro/submissions/404323

void citire(){
    in>>n;
    for(int i = 1; i <= n; z++){
        for(x = 1; x <= z; x++)
            for(y = 1; y <= z; y++, i++)
                in>>dp[x][y][z];
    }
    z--;
}

int main(){

    for(int strat = 0; strat < dpSIZE; strat++){
        for(x = 0, y = 0; x <= strat + 1; x++) dp[x][y][strat] = costMax;
        for(x = 0, y = 0; y <= strat + 1; y++) dp[x][y][strat] = costMax;
        for(x = 0, y = strat + 1; x <= strat + 1; x++) dp[x][y][strat] = costMax;
        for(x = strat + 1, y = 0; y <= strat + 1; y++) dp[x][y][strat] = costMax;
    }
    citire();

    for(int strat = 2; strat <= z; strat++){
        for(x = 1; x <= strat; x++)
            for(y = 1; y <= strat; y++)
                dp[x][y][strat] += min(dp[x][y][strat - 1], min(dp[x - 1][y][strat - 1],
                                   min(dp[x][y - 1][strat - 1], dp[x - 1][y - 1][strat - 1])));
    }
    for(x = 1; x <= z; x++)
        for(y = 1; y <= z; y++)
            cost = min(cost, dp[x][y][z]);

    out<<z<<" "<<cost;
    return 0;
}
