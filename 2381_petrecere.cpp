#include <fstream>
using namespace std;
ifstream in("petrecere.in");
ofstream out("petrecere.out");

///https://www.pbinfo.ro/probleme/2381/petrecere
///https://www.pbinfo.ro/detalii-evaluare/51581275
///https://kilonova.ro/submissions/404226

typedef int NrMare[3002];
void Suma(NrMare x, NrMare y){
	int i, t = 0; x[0] = max(x[0], y[0]);
    for(i = 1; i <= x[0]; i++, t /= 10)
        t += x[i] + y[i], x[i] = t % 10;
    for(; t; t /= 10) x[++x[0]] = t % 10;
}
void Produs(NrMare x, int n){
	int i, t = 0;
    for(i = 1; i <= x[0]; i++, t /= 10)
        t += x[i] * n, x[i] = t % 10;
    for(; t; t /= 10) x[++x[0]] = t % 10;
}
void Egalare(NrMare a, NrMare b){
	for(int i = 0; i <= b[0]; i++) a[i] = b[i];
}
void Afis(NrMare x){
	for(int i = x[0]; i >= 1; i--)
        out<<x[i]; out<<"\n";
}

///dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
int n; NrMare dp1 = {1, 1}, dp2 = {1, 1}, dp3;
int main(){
	in>>n;
    if(n == 1){
    	Afis(dp1);
    }else if(n == 2){
    	Afis(dp2);
    }else{
        for(int i = 2; i <= n; i++){
        	Egalare(dp3, dp1);
            Produs(dp3, (i - 1));
            Suma(dp3, dp2);

            Egalare(dp1, dp2);
            Egalare(dp2, dp3);
        }
    	Afis(dp2);
    }
    return 0;
}
