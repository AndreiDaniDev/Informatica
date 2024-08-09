#include <fstream>
using namespace std;
ifstream in("chimic.in");
ofstream out("chimic.out");
int n, st[100002], dr[100002], v[100002];
int64_t A[100002 << 2], dp[100002];

///https://www.pbinfo.ro/probleme/2226/chimic
///https://www.pbinfo.ro/detalii-evaluare/51725337

const int sizee = (1 << 6);
int index = sizee - 1;
char buffer[sizee];

char next(){
    index++;
    if(index == sizee){
        index = 0;
        in.read(buffer, sizee);
    }
    return buffer[index];
}

int get(){
    int x = 0; char t_; bool neg = false;
    for(t_ = next(); isspace(t_); t_ = next());
    for(neg = (t_ == '-');('0' <= t_ && t_ <= '9') || t_ == '-'; t_ = next())
        if('0' <= t_ && t_ <= '9') x = 10 * x + t_ - '0';
    return x * ((neg == 1) ? -1 : 1);
}

void update(int nod, int st, int dr, int pos, int64_t val){
    if(st == dr){
        A[nod] = val;
    }else{
        int mij = (st + dr) >> 1;
        if(pos <= mij)
            update((nod << 1), st, mij, pos, val);
        else
            update((nod << 1) + 1, mij + 1, dr, pos, val);
        A[nod] = max(A[(nod << 1)], A[(nod << 1) + 1]);
    }
}

int64_t maxQuery = -(1 << 30), p;
void query(int nod, int st, int dr, int stq, int drq){
    if(stq <= st && dr <= drq){
        maxQuery = max(maxQuery, A[nod]);
    }else{
        int mij = (st + dr) >> 1;
        if(stq <= mij)
            query((nod << 1), st, mij, stq, drq);
        if(mij < drq)
            query((nod << 1) + 1, mij + 1, dr, stq, drq);
    }
}

int main(){
    n = get();
    for(int i = 1; i <= n; i++)
        v[i] = get();
    for(int i = 1; i <= n; i++)
        st[i] = get(), dr[i] = get();
    for(int i = n; i >= 1; i--){
        if(st[i] == -1){
            dp[i] = v[i];
        }else{
            maxQuery = -(1 << 30);
            query(1, 1, n, st[i], dr[i]);
            dp[i] = v[i] + maxQuery;
        }
        update(1, 1, n, i, dp[i]);
    }
    for(int i = 1; i <= n; i++)
        p = max(p, dp[i]);
    out<<p;
    return 0;
}
