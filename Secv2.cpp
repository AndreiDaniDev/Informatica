#include <fstream>
#include <string>
using namespace std;
ifstream in("secv2.in");
ofstream out("secv2.out");
int64_t n, k, sp[50002], best = -(1 << 30), mini = (1 << 30);
int64_t sMax = 0, st, dr, st_;

///https://www.infoarena.ro/problema/secv2
///https://www.infoarena.ro/job_detail/3236832
///https://www.infoarena.ro/job_detail/3236832?action=view-source

string buffer;
int citire(){
    in>>buffer; int rez = 0;
    for(int i = 0; i < buffer.size(); i++)
        if('0' <= buffer[i] && buffer[i] <= '9')
            rez = 10 * rez + buffer[i] - '0';
    return rez * ((buffer[0] == '-') ? -1 : 1);
}

int main(){
    n = citire(); k = citire();
    for(int i = 1; i <= n; i++)
        sp[i] = citire(), sp[i] += sp[i - 1];
    ///best = sp[k];
    for(int i = k; i <= n; i++){
        ///mini = min(mini, sp[i - k]);
        ///best = max(best, sp[i] - mini);
        if(mini > sp[i - k])
            mini = sp[i - k], st_ = i - k + 1;
        if(best < sp[i] - mini)
            best = sp[i] - mini, st = st_, dr = i;
    }
    out<<st<<" "<<dr<<" "<<best;
    return 0;
}
