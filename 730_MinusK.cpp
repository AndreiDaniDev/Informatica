#include <fstream>
using namespace std;
ifstream in("minusk.in");
ofstream out("minusk.out");
int n, k, pplus[1000002], mminus[1000002];
///https://www.pbinfo.ro/probleme/730/minusk
///https://www.pbinfo.ro/detalii-evaluare/51465438
///https://kilonova.ro/submissions/393782
int main(){
    in>>n>>k;
    pplus[0] = 1; mminus[0] = 1;
    pplus[1] = 1; mminus[1] = 1;

    for(int i = 2; i <= n; i++){
        pplus[i] = (pplus[i - 1] + mminus[i - 1]) % 2011;
        mminus[i] = (2011 + pplus[i - 1] + mminus[i - 1] - ((k <= i) ? pplus[i - k] : 0)) % 2011;
    }

    (k == 1) ? out << 0 : out << (pplus[n] + mminus[n]) % 2011;

    return 0;
}
