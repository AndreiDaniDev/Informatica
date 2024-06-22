#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("mario.in");
ofstream out("mario.out");
///https://www.pbinfo.ro/probleme/696/mario
///https://www.pbinfo.ro/detalii-evaluare/51465757
///https://kilonova.ro/submissions/393790
struct platforma { int stanga, dreapta, inaltmie; } v[100000];
bool sortPlatforme(platforma A, platforma B){ return A.inaltmie < B.inaltmie; }
int x, y, h, n; bool obt; int64_t dp[10000], rez;
int main(){
    in>>y>>x>>h>>n;
    for(int i = 0; i < n; i++)
        in>>v[i].inaltmie>>v[i].stanga>>v[i].dreapta;
    sort(v, v + n, sortPlatforme);
    
    for(int i = n - 1; i >= 0; i--){
        if(v[i].inaltmie <= y && v[i].stanga <= x && x <= v[i].dreapta){
            dp[i] = 1; break;
        }
    }
    
    for(int i = n - 1, j; i >= 0; i--){
        if(dp[i] != 0){
            for(j = i - 1, obt = 0; v[i].inaltmie - v[j].inaltmie <= h && j >= 0; j--){
                if(v[j].stanga <= v[i].stanga && v[i].stanga <= v[j].dreapta){
                    dp[j] += dp[i]; obt = 1; break;
                }
            }
            rez += dp[i] * (!obt && v[i].inaltmie <= h);
            
            for(j = i - 1, obt = 0; v[i].inaltmie - v[j].inaltmie <= h && j >= 0; j--){
                if(v[j].stanga <= v[i].dreapta && v[i].dreapta <= v[j].dreapta){
                    dp[j] += dp[i]; obt = 1; break;
                }
            }
            rez += dp[i] * (!obt && v[i].inaltmie <= h);
        }
    }
    out<<rez;
    return 0;
}
