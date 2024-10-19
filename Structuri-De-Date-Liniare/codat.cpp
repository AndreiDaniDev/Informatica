#include <fstream>
#include <stack>
using namespace std;
ifstream in("codat.in");
ofstream out("codat.out");
const int sizee = 1000002;
int n, maxi, v[sizee], lf[sizee], rg[sizee];
stack <int> st, dr;
///https://kilonova.ro/submissions/455136
///https://www.pbinfo.ro/probleme/1130/codat
///https://www.pbinfo.ro/detalii-evaluare/53145947
int main(){
    in>>n;
    for(int i = 1; i <= n; i++){
        in>>v[i], maxi = max(maxi, v[i]);
    }
    for(int i = 1; i <= n; i++){
        for(; !st.empty() && v[i] >= v[st.top()]; st.pop());
        lf[i] = (st.empty() ? 0 : st.top()); st.push(i);
    }
    for(int i = n; i >= 1; i--){
        for(; !dr.empty() && v[i] >= v[dr.top()]; dr.pop());
        rg[i] = (dr.empty() ? 0 : dr.top()); dr.push(i);
    }
    for(int i = 1; i <= n; i++){
        if(v[i] == maxi)
            v[i] = -1;
        else if(lf[i] == 0) v[i] = rg[i];
        else if(rg[i] == 0) v[i] = lf[i];
        else if((i - lf[i]) == (rg[i] - i))
            v[i] = rg[i];
        else if((i - lf[i]) > (rg[i] - i))
            v[i] = rg[i]; else v[i] = lf[i];
    }
    for(int i = 1; i <= n; i++)
        out<<v[i]<<" ";
    return 0;
}
