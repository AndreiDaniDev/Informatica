#include <fstream>
using namespace std;
ifstream in("radioactiv.in");
ofstream out("radioactiv.out");
const int dim = 25;
int sume[1000 + 2 * dim][1000 + 2 * dim];
int n, k, suma, sumaMin = 2147483647, dis, aparitii;
///https://www.pbinfo.ro/detalii-evaluare/50373274
///https://www.pbinfo.ro/probleme/731/radioactiv
///https://kilonova.ro/submissions/393781
int sumaP(int is, int ij, int js, int jj){ 
    return sume[ij][jj] - sume[is-1][jj] - sume[ij][js-1] + sume[is-1][js-1]; 
}

int main()
{
    in>>n>>k;
    for(int i = dim; i < n+dim+k; i++)
        for(int j = dim; j < n+dim+k; j++)
            (i < n + dim && j < n + dim) ? in>>sume[i][j], 
                sume[i][j] += sume[i-1][j] + sume[i][j-1] - sume[i-1][j-1] : 
                sume[i][j] += sume[i-1][j] + sume[i][j-1] - sume[i-1][j-1];

    for(int i = dim; i < n+dim; i++){
        for(int j = dim; j < n+dim; j++){
            for(dis = 0, suma = 0; dis < k; dis++)
                suma += sumaP(i-dis,i+dis,j-dis,j+dis);
            if(suma < sumaMin)
                sumaMin = suma, aparitii = 1;
            else if(suma == sumaMin)
                aparitii += 1;
        }
    }
    out<<aparitii;
    return 0;
}
