#include <fstream>
using namespace std;
ifstream in("rmq.in");
ofstream out("rmq.out");
///https://www.infoarena.ro/problema/rmq
///https://www.infoarena.ro/job_detail/3239808
int n, m, st, dr, e, Log[100002], rmq[17][100002];
int main(){
    in>>n>>m; Log[0] = -1;
    for(int i = 1; i <= n; i++)
        in>>rmq[0][i], Log[i] = 1 + Log[i >> 1];
    for(int p = 1; (1 << p) <= n; p++){
        for(int i = 1; i <= n; i++){
            rmq[p][i] = rmq[p - 1][i];
            e = i + (1 << (p - 1));
            if(e <= n && rmq[p - 1][e] < rmq[p][i])
                rmq[p][i] = rmq[p - 1][e];
        }
    }
    for(int i = 1; i <= m; i++){
        in>>st>>dr;
        e = Log[dr - st + 1];
        out<<min(rmq[e][st], rmq[e][dr - (1 << e) + 1])<<"\n";
    }
    return 0;
}
