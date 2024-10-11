#include <iostream>
#include <stack>
#define queries st
using namespace std;
const int sizee = 100002, maxnr = 15000;
int task, n, q, val, maxi, v[sizee], st[sizee], dr[sizee];
stack <int> sst, sdr; int maxarie;
///https://www.pbinfo.ro/probleme/3453/jungla
///https://www.pbinfo.ro/detalii-evaluare/52701121
int f(int x){
    return (x & (-x));
}
void add(int x, int y){
    for(int i = x; i <= maxnr; i += f(i))
        v[i] += y;
}
int sum(int x){
    int s = 0;
    for(int i = x; i >= 1; i -= f(i))
        s += v[i];
    return s;
}
int main(){
    cin>>task;
    if(task == 1){
        cin>>n>>q;
        for(int i = 1; i <= n; i++){
            cin>>val;
            queries[i] = sum(val - 1);
            add(val, 1);
        }
        for(int i = 1; i <= q; i++)
            cin>>val, cout<<queries[val]<<"\n";
    }else if(task == 2){
        cin>>n;
        for(int i = 1; i <= n; i++){
            cin>>v[i]; maxi = max(maxi, v[i]);
            for(; !sst.empty() && v[i] >= v[sst.top()]; sst.pop());
            st[i] = ((sst.empty()) ? 1 : sst.top() + 1); sst.push(i);
        }
        for(int i = n; i >= 1; i--){
            for(; !sdr.empty() && v[i] >= v[sdr.top()]; sdr.pop());
            dr[i] = ((sdr.empty()) ? n : sdr.top() - 1); sdr.push(i);
        }
        for(int i = 1; i <= n; i++)
            maxarie = max(maxarie, (maxi - v[i]) * (dr[i] - st[i] + 1));
        cout<<maxarie;
    }
    return 0;
}
