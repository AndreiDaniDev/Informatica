#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;
ifstream in("2d.in");
ofstream out("2d.out");

const int distMax = 2000000002, distMin = 1000;
float x; int n, k, v[200002]; string buffer;
int st = distMin, dr = distMax, mij, sol = distMin;

///https://www.pbinfo.ro/probleme/705/2d
///https://www.pbinfo.ro/detalii-evaluare/51456922
///https://kilonova.ro/submissions/393074

bool ok(int lungime){
    int seg = -distMax, nrseg = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > seg) nrseg += 1, seg = v[i] + lungime;
        if(nrseg > k) return 0;
    }
    return 1;
}

int Citire(){
    in>>buffer; int rez = 0;
    for(int i = 0; i < buffer.size(); i++)
        if(buffer[i] >= '0' && buffer[i] <= '9')
            rez = rez * 10 + (buffer[i] - '0');
    return rez * ((buffer[0] == '-') ? -1 : 1);
}

int main(){
    n = Citire(), k = Citire();
    for(int i = 0; i < n; i++)
        v[i] = Citire(), Citire();

    sort(v, v + n);
    for(; st <= dr; ){
        mij = (st + dr) / 2;
        if(ok(mij)) sol = mij, dr = mij - 1;
        else st = mij + 1;
    }

    out<<fixed<<setprecision(3)<<(float) sol / 1000;
    return 0;
}
