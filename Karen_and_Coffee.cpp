#include <iostream>
using namespace std;
const int dim = 200002;
///https://codeforces.com/contest/816/submission/265977111
int n, k, q, smen[dim], smenQuery[dim], st, dr, t_;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>k>>q;
    for(int i = 1; i <= n; i++)
        cin>>st>>dr, smen[st]++, smen[dr + 1]--;

    for(int i = 1; i <= dim; i++){
        smen[i] += smen[i - 1];
        smenQuery[i] += (smen[i] >= k);
        smenQuery[i] += smenQuery[i - 1];
    }

    for(int i = 1; i <= q; i++)
        cin>>st>>dr, cout<<smenQuery[dr] - smenQuery[st - 1]<<'\n';
    return 0;
}
