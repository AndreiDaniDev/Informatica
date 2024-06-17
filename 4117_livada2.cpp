#include <fstream>
#include <bitset>
using namespace std;
///https://www.pbinfo.ro/detalii-evaluare/51437730
///https://www.pbinfo.ro/probleme/4177/livada2
ifstream in("livada2.in");
ofstream out("livada2.out");
const int dim = 100002;
int n, t, c, x, y, p, smen[dim], v[dim];
bitset <dim> mere; int st[dim], dr[dim];
int main(){
    in>>n;
    for(int i = 1; i <= n; i++) in>>v[i];
    for(int i = 1; i <= n; i++) in>>p, mere[i] = (p == 1);

    for(int i = 1; i <= n; i++) st[i] = (mere[i]) ? i : st[i - 1];
    for(int i = n; i >= 1; i--) dr[i] = (mere[i]) ? i : dr[i + 1];

    in>>t;
    for(int i = 1; i <= t; i++){
        in>>c>>x>>y>>p;
        if(c == 1) {
            if(dr[y] == 0) smen[x] += p, smen[y + 1] -= p;
            else smen[x] += p, smen[dr[y] + 1] -= p;
        } else if (c == 2) {
            if(st[x] == 0) smen[x] -= p, smen[y + 1] += p;
            else smen[st[x]] -= p, smen[y + 1] += p;
        }
    }

    for(int i = 1; i <= n; i++){
        smen[i] += smen[i - 1];
        v[i] += smen[i];
        out<<v[i]<<" ";
    }

    return 0;
}
