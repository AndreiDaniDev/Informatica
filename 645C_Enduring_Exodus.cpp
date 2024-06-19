#include <iostream>
#include <vector>
///https://codeforces.com/contest/645/submission/266431384
using namespace std;
int n, k, m, dist; vector <int> v; char s;
int main(){
    cin >> n >> k; dist = 2 * n;
    for(int p = 0; p < n && cin>>s; p++) 
        if(s == '0') v.push_back(p);
    
    for(int p = k; p < v.size(); p++) {
        for(; v[m] - v[p - k] <= v[p] - v[m]; m++);
        int st(v[m] - v[p - k]), dr(v[p] - v[m]), mx = (st > dr) ? st : dr;
        dist = (dist < mx) ? dist : mx; st = v[m - 1] - v[p - k]; dr = v[p] - v[m - 1];
        mx = (st > dr) ? st : dr; dist = (dist < mx) ? dist : mx;
    }
    
    cout << dist;
    return 0;
}
