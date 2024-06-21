#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
///https://www.pbinfo.ro/detalii-evaluare/51460021
///https://www.pbinfo.ro/probleme/4460/bossfight
///https://kilonova.ro/problems/635
ifstream in("bossfight.in");
ofstream out("bossfight.out");

int n,m,i,y,x,v[100001]; int64_t rez;
int main(){
    in>>n>>m; for(i = 0; i < n; i++) in>>v[i];
    vector<int> dr, st(v,v+n); sort(st.begin(),st.end());
    for(i = n - 1; i >= 0; i--) {
        st.erase(lower_bound(st.begin(),st.end(),v[i]));
        for(x = 0, y = st.size(); x < dr.size(); x++) {
            for(; y > 0 && (st[y - 1] >= v[i] || st[y - 1] + v[i] > m - dr[x]); y--);
            if(v[i]<dr[x]) rez+=y;
        }
        dr.insert(lower_bound(dr.begin(),dr.end(),v[i]),v[i]);
    }
    out<<rez;
    return 0;
}
