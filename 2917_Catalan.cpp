#include <iostream>
using namespace std;

///https://www.pbinfo.ro/probleme/2917/catalan
///https://www.pbinfo.ro/detalii-evaluare/51703316

typedef int NrMare[40000];
void Produs(NrMare x, int n){
    int i, t = 0;
    for(i = 1; i <= x[0]; i++, t/=10)
        t += x[i] * n, x[i] = t % 10;
    for(; t; t/=10) x[++x[0]] = t % 10;
}
int Divide(NrMare x, int n){
    int i, r = 0;
    for(i = x[0]; i >= 1; i--)
        r = 10 * r + x[i], x[i] = r / n, r %= n;
    for(; x[x[0]] == 0 && x[0] > 1; x[0]--);
    return r;
}
void Afis(NrMare x){
    for(int i = x[0]; i >= 1; i--)
        cout<<x[i];
    cout<<'\n';
}
void catalan(int n, NrMare rez){
    /*
    Catalan(n) = (2n)! // (n!)((n+1)!)
    = (n!) * (n + 1) * (n + 2) * ... * (n + n) // (n!)((n + 1)!)
    = (n + 1) * (n + 2) * ... * (2n) // (n + 1)!
    */
    rez[0] = 1, rez[1] = 1;
    for(int i = n + 1; i <= 2 * n; i++)
        Produs(rez, i);
    for(int i = 2; i <= n + 1; i++)
        Divide(rez, i);
}
int n, k; NrMare rez;
int main(){
    cin>>n;
    catalan(n, rez);
    Afis(rez);
    return 0;
}
