#include <bits/stdc++.h>
using namespace std;
///https://www.pbinfo.ro/probleme/3540/ambuscada
///https://www.pbinfo.ro/detalii-evaluare/51444421
ifstream in ("ambuscada.in");
ofstream out ("ambuscada.out");
vector < pair< int,int > > v;
int n,m,vieti,dmg,st,dr,ans = 0;
int main(){
    in >> n >> m >> vieti;
    v.push_back(make_pair(1,vieti));
    for(int i=1; i<=m; ++i){
        in >> st >> dr >> dmg;
        v.push_back(make_pair(st,-dmg));
        v.push_back(make_pair(dr+1,dmg));
    }
    sort(v.begin(),v.end());
    int S = 0, i = 0, j;
    for(i = 0; i < v.size(); i = j){
        for(j = i; v[i].first == v[j].first && j<v.size(); S += v[j].second, j++); 
        if(S>0) (j<v.size()) ? ans += v[j].first - v[i].first : ans += n - v[i].first + 1;
    }
    out << ans;
    return 0;
}
