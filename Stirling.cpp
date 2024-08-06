#include <fstream>
using namespace std;
ifstream in("stirling.in");
ofstream out("stirling.out");
int teste, speta, n, m;
int stirling[2][202][202];
///https://www.infoarena.ro/problema/stirling
///https://www.infoarena.ro/job_detail/3239606?action=view-source
int main(){
    in>>teste;

    stirling[0][1][1] = 1;
    stirling[1][1][1] = 1;

    for(int i = 2; i < 202; i++){
        for(int j = 1; j <= i; j++){
            stirling[0][i][j] = (stirling[0][i - 1][j - 1] - ((i - 1) * stirling[0][i - 1][j])) % 98999;
            stirling[1][i][j] = (stirling[1][i - 1][j - 1] + (j * stirling[1][i - 1][j])) % 98999;
        }
    }

    for(int i = 1; i <= teste; i++)
        in>>speta>>n>>m, out<<stirling[speta - 1][n][m]<<"\n";
    return 0;
}
