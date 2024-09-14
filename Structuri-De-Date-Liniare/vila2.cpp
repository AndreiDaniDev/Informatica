#include <fstream>
#include <utility>
#include <deque>
using namespace std;
ifstream in("vila2.in");
ofstream out("vila2.out");
typedef pair <int, int> pii;
int n, k, x, diffmax = -(1 << 30);
deque <pii> dqmax, dqmin;
///https://www.infoarena.ro/job_detail/3242868
///https://www.infoarena.ro/job_detail/3242862
int main(){
    in>>n>>k; k++;
    for(int i = 1; i <= k; i++){
        in>>x;
        for(; !dqmin.empty() && dqmin.back().first >= x; dqmin.pop_back());
        dqmin.push_back(make_pair(x, i));

        for(; !dqmax.empty() && dqmax.back().first <= x; dqmax.pop_back());
        dqmax.push_back(make_pair(x, i));
    }
    for(int i = k + 1; i <= n; i++){
        in>>x;

        for(; !dqmin.empty() && dqmin.front().second < (i - k + 1); dqmin.pop_front());
        for(; !dqmin.empty() && dqmin.back().first >= x; dqmin.pop_back());
        dqmin.push_back(make_pair(x, i));

        for(; !dqmax.empty() && dqmax.front().second < (i - k + 1); dqmax.pop_front());
        for(; !dqmax.empty() && dqmax.back().first <= x; dqmax.pop_back());
        dqmax.push_back(make_pair(x, i));

        diffmax = max(diffmax, dqmax.front().first - dqmin.front().first);
    }
    out<<diffmax;
    return 0;
}
