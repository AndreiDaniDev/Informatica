#include <fstream>
#define int uint64_t
using namespace std;
///https://www.pbinfo.ro/detalii-evaluare/49302436
///https://www.pbinfo.ro/probleme/734/miere
ifstream in("miere.in");
ofstream out("miere.out");
int n, sp[50002], t, q;

int solve(int q, int zi){
    if(sp[1] > q) return 0;
    int st = 1, dr = n, mij, pos = 0;
    for(; st <= dr; ){
        mij = (st + dr) / 2;
        if(sp[mij] + (zi - 1) * mij > q) dr = mij - 1;
        else st = mij + 1, pos = mij;
    }
    return pos;
}

int32_t main(){
    in>>n; for(int i = 1; i <= n; i++) in>>sp[i], sp[i] += sp[i - 1];
    in>>t; for(int i = 1; i <= t; i++) in>>q, out<<solve(q, i)<<'\n';
    return 0;
}
