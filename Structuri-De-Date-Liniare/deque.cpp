#include <fstream>
#include <utility>
#include <deque>
using namespace std;
ifstream in("deque.in");
ofstream out("deque.out");
int n, k, x; int64_t sum; deque < pair <int, int> > dq;
///https://www.infoarena.ro/job_detail/3242125
int main(){
    in>>n>>k;
    for(int i = 1; i <= k; i++){
        in>>x;
        for(; !dq.empty() && dq.back().first >= x; dq.pop_back());
        dq.push_back(make_pair(x, i));
    }
    sum += (1ll * dq.front().first);
    for(int i = k + 1; i <= n; i++){
        in>>x;
        for(; !dq.empty() && dq.front().second < (i - k + 1); dq.pop_front());
        for(; !dq.empty() && dq.back().first >= x; dq.pop_back());
        dq.push_back(make_pair(x, i)); sum += (1ll * dq.front().first);
    }
    out<<sum;
    return 0;
}
