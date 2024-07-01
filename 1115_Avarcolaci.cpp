#include <fstream>
#include <string>
using namespace std;
ifstream in1("avarcolaci.in");
ifstream in2("avarcolaci.in");
ofstream out("avarcolaci.out");
int t, n, v, c, f, p; string buffer;
///https://www.pbinfo.ro/probleme/1115/avarcolaci
///https://www.pbinfo.ro/detalii-evaluare/51507582
///https://kilonova.ro/submissions/397935
int Citire1(){
    in1>>buffer; int rez = 0;
    for(int i = 0; i < buffer.size(); i++)
        if(buffer[i] >= '0' && buffer[i] <= '9')
            rez = rez * 10 + (buffer[i] - '0');
    return rez * ((buffer[0] == '-') ? -1 : 1);
}
int Citire2(){
    in2>>buffer; int rez = 0;
    for(int i = 0; i < buffer.size(); i++)
        if(buffer[i] >= '0' && buffer[i] <= '9')
            rez = rez * 10 + (buffer[i] - '0');
    return rez * ((buffer[0] == '-') ? -1 : 1);
}

void solve(){
    n = Citire1(); Citire2();
    c = 0, f = 0, p = 0, v = 0;
    for(int i = 0; i < n * 2; i++){
        v = Citire1();
        if(c == 0) c += 1, p = v;
        else if(p == v) c += 1;
        else c -= 1;
    }
    for(int i = 0; i < n * 2; i++){
        v = Citire2();
        f += (v == p);
    }
    if(f < n || c == 0) out<<"Mozart\n";
    else out<<p<<"\n";
}

int main(){
    t = Citire1(); Citire2();
    for(int test = 0; test < t; test++)
        solve();
    return 0;
}
