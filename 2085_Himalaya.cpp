#include <fstream>
using namespace std;
ifstream in("himalaya.in");
ofstream out("himalaya.out");
int n, k, j_, c1, c2, h[502], dp[502][502], traseu[502][502], sizee, solutie[502];
///https://www.pbinfo.ro/probleme/2085/himalaya
///https://www.pbinfo.ro/detalii-evaluare/51786737
int cost(int i, int j){
    if(h[i] <= h[j])
        return (h[j] - h[i]) * c1;
    return (h[i] - h[j]) * c2;
}

int main(){
    in>>n>>k>>c1>>c2;
    for(int i = 1; i <= n; i++)
        in>>h[i];
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++)
            dp[i][j] = -(1 << 30);
    }
    dp[1][1] = 0;
    for(int p = 2; p <= k; p++){
        for(int i = p; i <= n; i++){
            j_ = p - 1;
            for(int j = p - 1; j < i; j++)
                if((dp[p - 1][j] + cost(i, j)) > (dp[p - 1][j_] + cost(i, j_))) j_ = j;
            dp[p][i] = dp[p - 1][j_] + cost(i, j_);
            traseu[p][i] = j_;
        }
    }
    for(int t = n; k; k--){
    	solutie[++sizee] = t;
        t = traseu[k][t];
    }
    for(int i = sizee; i >= 1; i--)
        out<<solutie[i]<<" ";
    return 0;
}
