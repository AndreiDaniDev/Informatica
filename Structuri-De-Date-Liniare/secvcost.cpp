#include <fstream>
#include <stack>
using namespace std;
ifstream in("secvcost.in");
ofstream out("secvcost.out");
const int sizee = 200002;
int n, queries, val, a, b; int64_t v[sizee];
int lf[sizee], rg[sizee];
stack <int> st, dr;
///https://www.pbinfo.ro/probleme/3652/secvcost
///https://www.pbinfo.ro/detalii-evaluare/52925714
int main(){
    in>>n>>queries;
    for(int i = 1; i <= n; i++)
        in>>v[i];
    for(int i = 1; i <= n; i++){
        for(; !st.empty() && v[i] >= v[st.top()]; st.pop());
        lf[i] = (st.empty()) ? 1 : st.top() + 1; st.push(i);
    }
    for(int i = n; i >= 1; i--){
        for(; !dr.empty() && v[i] >= v[dr.top()]; dr.pop());
        rg[i] = (dr.empty()) ? n : dr.top() - 1; dr.push(i);
    }
    for(int i = 1; i <= n; i++){
        v[i] = 1ll * v[i] * (rg[i] - lf[i] + 1);
        v[i] += v[i - 1];
    }
    for(int i = 1; i <= queries; i++)
        in>>a>>b, out<<v[b] - v[a - 1]<<"\n";
    return 0;
}
