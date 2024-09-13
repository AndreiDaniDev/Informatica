#include <fstream>
#include <deque>
using namespace std;
ifstream in("sum2.in");
ofstream out("sum2.out");
const int sizee = 100001;
int n, st, dr, sp[sizee + 2], smax = -(1 << 30);
///https://www.infoarena.ro/job_detail/3242722
deque <int> dq;
int main(){
    in>>n>>st>>dr;
    for(int i = 1; i <= n; i++)
        in>>sp[i], sp[i] += sp[i - 1];
    for(int i = st; i <= n; i++){
        for(; !dq.empty() && sp[dq.back()] >= sp[i - st]; dq.pop_back());
        for(; !dq.empty() && dq.front() < (i - dr); dq.pop_front());
        dq.push_back(i - st);
        smax = max(smax, sp[i] - sp[dq.front()]);
    }
    out<<smax;
    return 0;
}
