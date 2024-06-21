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

int n, m, q, posX = 3, posY = 3;
cord startt, endd, perete, starttNorm, enddNorm;
vector <int> px, py, pxNorm({1}), pyNorm({1});

short smen[2502][2502];

int LeeCost(cord startt, cord endd){
    deque < pair <int, int > > coada;
    int cost = 0;
    
    
    
    return cost;
}

int main(){
    /// -> Citire <-
    in>>n>>m>>startt.x>>startt.y>>endd.x>>endd.y;

    starttNorm = make_pair(1,1);
    enddNorm = make_pair(1,1);

    px.push_back(startt.x); px.push_back(endd.x);
    py.push_back(startt.y); py.push_back(endd.y);

    in>>q;
    for(int i = 0; i < q; i++){
        in>>perete.x>>perete.y;
        px.push_back(perete.x);
        py.push_back(perete.y);
    }

    sort(px.begin(), px.end());
    sort(py.begin(), py.end());

    for(int i = 1; i < px.size(); i++){
        posX -= (px[i] - px[i - 1] == 1);
        posX -= 2 * (px[i] - px[i - 1] == 0);

        posY -= (py[i] - py[i - 1] == 1);
        posY -= 2 * (py[i] - py[i - 1] == 0);

        if(px[i] == startt.x) starttNorm.x = posX;
        if(py[i] == startt.y) starttNorm.y = posY;

        if(px[i] == endd.x) enddNorm.x = posX;
        if(py[i] == endd.y) enddNorm.y = posY;

        pxNorm.push_back(posX); pyNorm.push_back(posY);

        posX += 2; posY += 2;
    }

    n = pxNorm[pxNorm.size() - 1];
    m = pyNorm[pyNorm.size() - 1];
    
    /*
    for(int i = 0; i < pxNorm.size(); i++)
        out<<pxNorm[i]<<" ";
    out<<"\n";
    for(int i = 0; i < pyNorm.size(); i++)
        out<<pyNorm[i]<<" ";
    */
    
    out<<LeeCost(starttNorm, enddNorm);
    
    return 0;
}
