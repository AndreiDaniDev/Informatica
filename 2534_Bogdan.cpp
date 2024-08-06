#include <fstream>
using namespace std;
ifstream in("bogdan.in");
ofstream out("bogdan.out");

///https://www.pbinfo.ro/probleme/2534/bogdan
///https://www.pbinfo.ro/detalii-evaluare/51592013

int n, t, q, qx, qy, nods[400008], rezQuery, v[100002];

const int sizee = (1 << 6) - 1; 
char bufferFastIO[sizee]; 
int indexIO = sizee - 1;

char nextChar(){
    indexIO += 1;
    if(indexIO == sizee)
        indexIO = 0, in.read(bufferFastIO, sizee);
    return bufferFastIO[indexIO];
}

int fastIO(){
    int val = 0; char t_; bool neg = false;
    for(t_ = nextChar(); isspace(t_); t_ = nextChar());
    for(neg = (t_ == '-');('0' <= t_ && t_ <= '9') || t_ == '-'; t_ = nextChar())
        if('0' <= t_ && t_ <= '9') val = 10 * val + t_ - '0';
    return val * ((neg) ? -1 : 1);
}

void update(int nod, int st, int dr, int pos, int val){
    if(st == dr){
        nods[nod] = val;
    }else{
        int mij = (st + dr) >> 1;
        if(pos <= mij)
            update((nod << 1), st, mij, pos, val);
        else if(pos > mij)
            update((nod << 1) + 1, mij + 1, dr, pos, val);
        nods[nod] = (nods[(nod << 1)] + nods[(nod << 1) + 1]);
    }
}

void query(int nod, int st, int dr, int stQuery, int drQuery){
    if(stQuery <= st && dr <= drQuery){
        rezQuery += nods[nod];
    }else{
        int mij = (st + dr) >> 1;
        if(stQuery <= mij)
            query((nod << 1), st, mij, stQuery, drQuery);
        if(mij < drQuery)
            query((nod << 1) + 1, mij + 1, dr, stQuery, drQuery);
    }
}

int main(){
    n = fastIO();
    for(int i = 1; i <= n; i++)
        v[i] = fastIO(), update(1, 1, n, i, (v[i] < v[i - 1]));
    t = fastIO();
    for(int i = 1; i <= t; i++){
        q = fastIO(); qx = fastIO(); qy = fastIO();
        if(q == 1){
            v[qx] = qy;
            update(1, 1, n, qx, (v[qx] < v[qx - 1]));
            update(1, 1, n, qx + 1, (v[qx + 1] < v[qx]));
        }else{
            rezQuery = 0; query(1, 1, n, qx + 1, qy);
            (rezQuery == 0) ? out<<"DA \n" : out<<"NU \n";
        }
    }
    return 0;
}
