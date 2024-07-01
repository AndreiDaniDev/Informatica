#include <fstream>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;
ifstream in("slidingwindow.in");
ofstream out("slidingwindow.out");
///https://www.infoarena.ro/problema/slidingwindow
///https://www.infoarena.ro/job_detail/3236819
string buffer;
int Citire(){
    in>>buffer; int rez = 0;
    for(int i = 0; i < buffer.size(); i += 1)
        if('0' <= buffer[i] && buffer[i] <= '9')
            rez = 10 * rez + buffer[i] - '0';
    return rez * ((buffer[0] == '-') ? -1 : 1);
}

int n, d, k = 2000000002; pair <int, int> v[1000002];

int main(){
    n = Citire(), d = Citire();
    for(int i = 0; i < n; i++)
        v[i].first = Citire(), v[i].second = i;
    sort(v, v + n);

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n && v[j].first - v[i].first <= k; j++){
            if(abs(v[j].second - v[i].second) <= d)
                k = min(k, abs(v[j].first - v[i].first));
        }
    }

    out<<k;
    return 0;
}
