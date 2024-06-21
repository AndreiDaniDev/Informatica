#include <fstream>
#include <utility>
#include <deque>
#include <vector>
#include <algorithm>
#define cord pair<int,int>
#define x first
#define y second
using namespace std;
ifstream in("labir.in");
ofstream out("labir.out");

int n, m, q, posX = 3, posY = 3, posXX, posYY; cord startt, endd, perete;
vector < pair <int, int> > px, py; short smen[2502][2502];
bool margineX = 0, margineXX = 0, margineY = 0, margineYY = 0;

bool sortNorm(pair <int, int> a, pair <int, int> b){ return a.first < b.first; }
bool sortIndex(pair <int, int> a, pair <int, int> b){ return a.second < b.second; }
void verifBordura(cord obj){
    if(obj.x == 1) margineX = 1;
    if(obj.x == n) margineXX = 1;

    if(obj.y == 1) margineY = 1;
    if(obj.y == m) margineYY = 1;
}

int LeeCost(cord startt, cord endd){
    deque < pair <int, int > > coada;
    int cost = 0;



    return cost;
}

int main(){
    /// -> Citire <-
    in>>n>>m>>startt.x>>startt.y>>endd.x>>endd.y;
    verifBordura(startt); verifBordura(endd);

    px.push_back(make_pair(startt.x, -2)); px.push_back(make_pair(endd.x, -1));
    py.push_back(make_pair(startt.y, -2)); py.push_back(make_pair(endd.y, -1));

    in>>q;
    for(int i = 0; i < q; i++){
        in>>perete.x>>perete.y;
        px.push_back(make_pair(perete.x, i));
        py.push_back(make_pair(perete.y, i));
        verifBordura(perete);
    }

    sort(px.begin(), px.end(), sortNorm);
    sort(py.begin(), py.end(), sortNorm);

    /// ---> Verificare Margini <---

    posXX = px[0].first, posYY = py[0].first;

    if(margineX) px[0].first = 1, posX = 3;
    else px[0].first = 2, posX = 4;
    if(margineY) py[0].first = 1, posY = 3;
    else py[0].first = 2, posY = 4;

    for(int i = 1; i < px.size(); i++){
        posX -= (px[i].first - posXX == 1);
        posX -= 2 * (px[i].first - posXX == 0);

        posY -= (py[i].first - posYY == 1);
        posY -= 2 * (py[i].first - posYY == 0);

        posXX = px[i].first, posYY = py[i].first;

        px[i].first = posX; py[i].first = posY;

        posX += 2; posY += 2;
    }

    /// ---> Construire Matrice <---

    n = px[px.size() - 1].first + (margineXX == 0);
    m = py[py.size() - 1].first + (margineYY == 0);

    sort(px.begin(), px.end(), sortIndex);
    sort(py.begin(), py.end(), sortIndex);

    for(int i = 0; i < px.size(); i++)
        smen[px[i].first][py[i].first] = 1;

    smen[px[0].first][py[0].first] = 3;
    smen[px[1].first][py[1].first] = 2;
	/*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            out<<smen[i][j]<<" ";
        out<<"\n";
    }
	*/
    out<<LeeCost(make_pair(px[0].first, py[0].first),
                 make_pair(px[1].first, py[1].first));

    return 0;
}
