#include <iostream>
#include <vector>
///https://codeforces.com/contest/645/submission/266432644
using namespace std;
int n, k, m, dist = 200004; vector <int> v; char s;
int main(){
    cin >> n >> k;
    for(int p = 0; p < n && cin>>s; p++)
        if(s == '0') v.push_back(p);
 
    for(int p = k; p < v.size(); p++) {
        for(; v[m] - v[p - k] <= v[p] - v[m]; m++);
        dist = min(dist, max(v[m] - v[p - k], v[p] - v[m]));
        dist = min(dist, max(v[m - 1] - v[p - k], v[p] - v[m - 1]));
    }
 
    cout << dist;
    return 0;
}
