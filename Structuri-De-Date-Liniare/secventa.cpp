#include <fstream>
#include <utility>
#include <deque>
using namespace std;
ifstream in("secventa.in");
ofstream out("secventa.out");
int n, k, x, maxi, st, dr; deque < pair <int, int> > dq;
///https://www.infoarena.ro/job_detail/3242394
int main(){
    in>>n>>k;
    for(int i = 1; i <= k; i++){
        in>>x;
        for(; !dq.empty() && dq.back().first >= x; dq.pop_back());
        dq.push_back(make_pair(x, i));
    }
    maxi = dq.front().first; st = 1; dr = k;
    for(int i = k + 1; i <= n; i++){
        in>>x;
        for(; !dq.empty() && dq.front().second < (i - k + 1); dq.pop_front());
        for(; !dq.empty() && dq.back().first >= x; dq.pop_back());
        dq.push_back(make_pair(x, i));
        if(maxi < dq.front().first){
            maxi = dq.front().first;
            st = i - k + 1; dr = i;
        }
    }
    out<<st<<" "<<dr<<" "<<maxi;
    return 0;
}
