#include <fstream>
using namespace std;
ifstream in("aint.in");
ofstream out("aint.out");
int n, t, x, q, qx, qy, nods[400002];
///https://www.pbinfo.ro/probleme/1794/aint
///https://www.pbinfo.ro/detalii-evaluare/51534347
///https://www.pbinfo.ro/probleme/2090/actualizare-element-minim-interval
///https://www.pbinfo.ro/detalii-evaluare/51534412
void update(int nod, int st, int dr, int pos, int v){
    if(st == dr){
        nods[nod] = v;
    }else{
        int mij = (st + dr) >> 1;
        if(pos <= mij)
            update((nod << 1), st, mij, pos, v);
        else if(pos > mij)
            update((nod << 1) + 1, mij + 1, dr, pos, v);
        nods[nod] = min(nods[(nod << 1)], nods[(nod << 1) + 1]);
    }
    return;
}

int rezQuery = 0;
void query(int nod, int st, int dr, int stQuery, int drQuery){
    if(stQuery <= st && dr <= drQuery){
        rezQuery = min(rezQuery, nods[nod]);
    }else{
        int mij = (st + dr) >> 1;
        if(stQuery <= mij)
            query((nod << 1), st, mij, stQuery, drQuery);
        if(mij < drQuery)
            query((nod << 1) + 1, mij + 1, dr, stQuery, drQuery);
    }
    return;
}

int main(){
    in>>n>>t;
    for(int i = 1; i <= n; i++)
        in>>x, update(1, 1, n, i, x);
    for(int i = 0; i < t; i++){
        in>>q>>qx>>qy;
        if(q == 1){
            update(1, 1, n, qx, qy);
        }else{
            rezQuery = (1 << 30);
            query(1, 1, n, qx, qy);
            out<<rezQuery<<"\n";
        }
    }
    return 0;
}
