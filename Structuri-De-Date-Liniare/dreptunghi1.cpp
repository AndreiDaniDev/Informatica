#include <fstream>
#include <algorithm>
#include <utility>
#include <stack>
#define x first
#define y second
using namespace std;
ifstream in("dreptunghi1.in");
ofstream out("dreptunghi1.out");
typedef pair <int, int> pii;
const int sizee = 10002;
int n, m, k, dp[sizee], lf[sizee], rg[sizee];
pii pos[sizee]; int idx = 1, maxarie;
///https://www.pbinfo.ro/probleme/2665/dreptunghi1
///https://www.pbinfo.ro/detalii-evaluare/52894392
int main(){
    in>>n>>m>>k;
    for(int i = 1; i <= k; i++)
        in>>pos[i].x>>pos[i].y;
    sort(pos + 1, pos + 1 + k);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(pos[idx].x == i && pos[idx].y == j){
                dp[j] = 0; for(; pos[idx].x == i && pos[idx].y == j; idx++);
            }else{ dp[j] += 1; }
        }

        stack <int> st, dr;
        for(int j = 1; j <= m; j++){
            for(; !st.empty() && dp[j] <= dp[st.top()]; st.pop());
            lf[j] = ((st.empty()) ? 1 : st.top() + 1); st.push(j);
        }
        for(int j = m; j >= 1; j--){
            for(; !dr.empty() && dp[j] <= dp[dr.top()]; dr.pop());
            rg[j] = ((dr.empty()) ? m : dr.top() - 1); dr.push(j);
        }
        for(int j = 1; j <= m; j++)
            maxarie = max(maxarie, dp[j] * (rg[j] - lf[j] + 1));
    }
    out<<maxarie;
    return 0;
}
