///https://codeforces.com/contest/1221/submission/266224767
///https://codeforces.com/problemset/problem/1221/C
#include <iostream>
using namespace std;
int q, c, m, x;
int main(){
    cin>>q;
    for(int i = 0; i < q; i++){
        cin>>c>>m>>x;
        cout<<(((c + m + x) / 3 < min(c, m)) ? (c + m + x) / 3 : min(c, m))<<"\n";
    }
    return 0;
}
