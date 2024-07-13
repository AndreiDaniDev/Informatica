#include <fstream>
using namespace std;
ifstream in("cladire.in");
ofstream out("cladire.out");

/*
f[i][j] = numar de drumuri de la (1,1) la (i,j)
f[i][j] = (daca i == 1 || j == 1) -> 1 altfel f[i - 1][j] + f[i][j - 1];
*/

///https://www.pbinfo.ro/probleme/392/cladire
///https://www.pbinfo.ro/detalii-evaluare/51571127

///Redus la 2 linii
int n, m, f[3][1002];
int main(){
	in>>n>>m;
    for(int i = 1; i <= m; i++) f[1][i] = 1;
    f[1][1] = 1; f[2][1] = 1;
    
    for(int i = 2; i <= n; i++){
        if((i & 1) == 0){
        	for(int j = 2; j <= m; j++)
                f[2][j] = (f[1][j] + f[2][j - 1]) % 9901;
        }else{
        	for(int j = 2; j <= m; j++)
                f[1][j] = (f[2][j] + f[1][j - 1]) % 9901;
        }
    }
  	((n & 1) ? out<<f[1][m] : out<<f[2][m]);
    return 0;
}

/*
int n, m, f[1002][1002];
int main(){
    in>>n>>m;
    for(int i = 1; i <= n; i++) f[i][1] = 1;
    for(int i = 1; i <= m; i++) f[1][i] = 1;
    for(int i = 2; i <= n; i++)
        for(int j = 2; j <= m; j++)
            f[i][j] = (f[i - 1][j] + f[i][j - 1]) % 9901;
    out<<f[n][m];
    return 0;
}
*/
