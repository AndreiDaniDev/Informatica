#include <fstream>
using namespace std;
ifstream in("plaja1.in");
ofstream out("plaja1.out");
int n, m, u, p, z, ux[102], uy[102], x1, y1, x2, y2, sp[2002][2002];
///https://www.pbinfo.ro/probleme/2383/plaja1
///https://www.pbinfo.ro/detalii-evaluare/51466333
///https://kilonova.ro/submissions/393808
int prosoape, zone;
bool ok(int x1, int y1, int x2, int y2){
    for(int i = 0; i < u; i++){
        if(x1 <= ux[i] && ux[i] <= x2 && y1 <= uy[i] && uy[i] <= y2)
            return false;
    }
    return true;
}

int main(){
    in>>n>>m>>u;
    for(int i = 0; i < u; i++){
        in>>ux[i]>>uy[i];
        sp[ux[i]][uy[i]] += 1;
        sp[ux[i] + 1][uy[i]] -= 1;
        sp[ux[i]][uy[i] + 1] -= 1;
        sp[ux[i] + 1][uy[i] + 1] += 1;
    }
    in>>p;
    for(int i = 0; i < p; i++){
        in>>x1>>y1>>x2>>y2;
        if(ok(x1,y1,x2,y2)){
            prosoape++;
            sp[x1][y1] += 1;
            sp[x2 + 1][y1] -= 1;
            sp[x1][y2 + 1] -= 1;
            sp[x2 + 1][y2 + 1] += 1;
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            sp[i][j] += sp[i - 1][j] + sp[i][j - 1] - sp[i - 1][j - 1];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            sp[i][j] += sp[i - 1][j] + sp[i][j - 1] - sp[i - 1][j - 1];

    /*for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++)
            out<<sp[i][j]<<" ";
        out<<"\n";
    }*/

    in>>z;
    for(int i = 0; i < z; i++){
        in>>x1>>y1>>x2>>y2;
        zone += ((sp[x2][y2] - sp[x2][y1-1] - sp[x1-1][y2] + sp[x1-1][y1-1]) == 0);
    }

    out<<prosoape<<" "<<zone;
    return 0;
}
