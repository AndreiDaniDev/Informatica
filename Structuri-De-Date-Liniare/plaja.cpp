#include <fstream>
#include <stack>
using namespace std;
ifstream in("plaja.in");
ofstream out("plaja.out");
const int sizee = 1002;
///https://www.pbinfo.ro/probleme/1267/plaja
///https://www.pbinfo.ro/detalii-evaluare/52820906
int n, m, maxarie, dp[sizee], lf[sizee], rg[sizee]; char val;
int main(){
    in>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            in>>val, dp[j] = ((val == '0') ? (dp[j] + 1) : 0);
        /*for(int j = 1; j <= m; j++)
            out<<dp[j]<<" ";
        out<<"\n";*/
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
