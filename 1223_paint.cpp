#include <fstream>
///https://www.pbinfo.ro/probleme/1233/paint
///https://www.pbinfo.ro/detalii-evaluare/51441713
using namespace std;
ifstream in("paint.in");
ofstream out("paint.out");
int n, k, m, v[250002], qa, qb, rez = 0;
int main(){
    in>>n>>k>>m;
    for(int i = 0; i < m; i++)
        in>>qa>>qb, v[qa]++, v[qa + qb]--;
    for(int i = 1; i < n; i++)
        v[i] += v[i - 1], rez += (v[i] < k);
    rez += (v[0] < k);
    out<<rez;
    return 0;
}
