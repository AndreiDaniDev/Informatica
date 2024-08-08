#include <fstream>
using namespace std;
ifstream in("schi.in");
ofstream out("schi.out");
int n, v[30002], locuri[30002], aib[30002];
///https://infoarena.ro/problema/schi
///https://infoarena.ro/job_detail/3239857
///https://sepi.ro/assets/upload-file/infobits-f1.pdf
///pag 13 (arbori indexati binar)
void add(int pos, int val){
    for(int i = pos; i <= n; i += (i & (-i)))
        aib[i] += val;
}
int sum(int pos){
    int rez = 0;
    for(int i = pos; i >= 1; i -= (i & (-i)))
        rez += aib[i];
    return rez;
}
int solve(int positie){
    int mij, st, dr, pos;
    for(st = 1, dr = n, pos = n + 1; st <= dr; ){
        mij = (st + dr) >> 1;
        if(sum(mij) < positie){
            st = mij + 1;
        }else{
            pos = mij, dr = mij - 1;
        }
    }
    add(pos, -1); return pos;
}
int main(){
    in>>n;
    for(int i = 1; i <= n; i++)
        in>>v[i], add(i, 1);
    for(int i = n; i >= 1; i--)
        locuri[solve(v[i])] = i;
    for(int i = 1; i <= n; i++)
        out<<locuri[i]<<"\n";
    return 0;
}
