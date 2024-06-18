#include <fstream>
using namespace std;
ifstream in("gogosi.in");
ofstream out("gogosi.out");
int n, x, q, v[1000001];
///https://www.pbinfo.ro/probleme/2297/gogosi
///https://www.pbinfo.ro/detalii-evaluare/51451496
int binarySearch(int x){
    int st = 0, dr = q - 1, mij;
    for(; st <= dr; ){
        mij = (st + dr) / 2;
        if(v[mij] > x) st = mij + 1;
        if(v[mij] < x) dr = mij - 1;
        if(v[mij] == x) return 0;
    }
    v[st] = x; if(st == q) q++;
    return 0;
}

int main(){
    in>>n;
    for(int i = 0; i < n; i++){
        in>>x;
        binarySearch(x);
    }
    out<<q;
	return 0;
}
