#include <fstream>
using namespace std;
ifstream in("veverita4.in");
ofstream out("veverita4.out");

///https://www.pbinfo.ro/probleme/4287/veverita4
///https://www.pbinfo.ro/detalii-evaluare/51598977

typedef int NrMare[1002];
void Suma(NrMare a, NrMare b, NrMare c){
    int i, t = 0; c[0] = max(a[0], b[0]);
    for(i = 1; i <= c[0]; i++, t /= 10)
        t += a[i] + b[i], c[i] = t % 10;
    for(; t; t /= 10) c[++c[0]] = t % 10;
}
int findRest(NrMare x, int n){
    int r = 0, i;
    for(i = x[0]; i >= 1; i--)
        r = 10 * r + x[i], r %= n;
    return r;
}
void Egalare(NrMare a, NrMare b){
    for(int i = 0; i <= b[0]; i++) a[i] = b[i];
}
void Afis(NrMare x){
    for(int i = x[0]; i >= 1; i--)
        out<<x[i]; out<<"\n";
}

int n, k, t1, t2, t3; NrMare dp1 = {1, 4}, dp2 = {1, 6}, dp3;
int main(){
    in>>n;
    if(n <= 1000){
        if(n <= 2){
            (n == 1) ? out<<4 : out<<6;
        }else{
            for(int i = 3; i <= n; i++){
                Suma(dp1, dp2, dp3);
                Egalare(dp1, dp2);
                Egalare(dp2, dp3);
            }
            Afis(dp3);
        }
    }else{
        t1 = 249651; t2 = 34433;

        if(n == 1001){
            out<<t1;
        }else if(n == 1002){
            out<<t2;
        }else{
            for(int i = 1003; i <= n; i++)
                t3 = (t1 + t2) % 666013, t1 = t2, t2 = t3;
            out<<t3;
        }
    }
    return 0;
}
