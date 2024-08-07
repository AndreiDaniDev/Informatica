#include <fstream>
using namespace std;
ifstream in("order.in");
ofstream out("order.out");
///https://infoarena.ro/problema/order
///https://infoarena.ro/job_detail/3239802
int n, A[30002 << 2];
void build(int nod, int st, int dr){
    if(st == dr){
        A[nod] = 1;
    }else{
        int mij = (st + dr) >> 1;
        build((nod << 1), st, mij);
        build((nod << 1) + 1, mij + 1, dr);
        A[nod] = A[(nod << 1)] + A[(nod << 1) + 1];
    }
}
void update(int nod, int st, int dr, int pos, int val){
    if(st == dr){
        A[nod] = val;
    }else{
        int mij = (st + dr) >> 1;
        if(pos <= mij)
            update((nod << 1), st, mij, pos, val);
        if(mij < pos)
            update((nod << 1) + 1, mij + 1, dr, pos, val);
        A[nod] = A[(nod << 1)] + A[(nod << 1) + 1];
    }
}
int query(int nod, int st, int dr, int pos){
    if(st == dr){
        return st;
    }else{
        int mij = (st + dr) >> 1;
        if(A[(nod << 1)] >= pos)
            return query((nod << 1), st, mij, pos);
        return query((nod << 1) + 1, mij + 1, dr, pos - A[(nod << 1)]);
    }
}
int main(){
    in>>n; build(1, 1, n);
    for(int i = 1, pos = 1, kuery; i <= n; i++){
        pos = (pos + i) % A[1];
        if(pos == 0) pos = A[1];
        kuery = query(1, 1, n, pos); update(1, 1, n, kuery, 0);
        pos -= 1; out<<kuery<<" ";
    }
    return 0;
}
