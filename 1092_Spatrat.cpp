#include <fstream>
#include <cmath>
#include <utility>
#define x first
#define y second
using namespace std;
ifstream in("spatrat.in");
ofstream out("spatrat.out");
///https://www.pbinfo.ro/probleme/1092/spatrat
///https://www.pbinfo.ro/detalii-evaluare/51778239
int n; pair <int, int> dp[100002];
int main(){
    in>>n;
    for(int i = 1; i <= n; i++)
        dp[i] = make_pair((1 << 30), (1 << 30));
    for(int i = sqrt(n); i >= 0; i--){
        for(int j = 0; j + i * i <= n; j++){
            if(dp[j + i * i].x > dp[j].x + 1)
                dp[j + i * i].x = dp[j].x + 1, dp[j + i * i].y = i;
        }
    }
    out<<dp[n].x<<"\n";
    for(; n; n -= dp[n].y * dp[n].y)
        out<<dp[n].y<<" ";
    return 0;
}
