#include <iostream>
#include <utility>
#include <queue>
using namespace std;
///https://www.pbinfo.ro/probleme/3277/lee
///https://www.pbinfo.ro/detalii-evaluare/51458854
int n, smen[102][102], smen1[102][102], dist; pair <int, int> query[5];
const int di[] = {-1, 0, 1, 0}, dj[] = {0, -1, 0, 1};

bool ok(pair <int, int> a){
    return (1 <= a.first && a.first <= n && 1 <= a.second && a.second <= n);
}

int Lee(pair <int, int> startt, pair <int, int> endd){

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            smen1[i][j] = 0;

    queue < pair <int, int> > coada;
    smen1[startt.first][startt.second] = 0;
    coada.push(startt);

    pair <int, int> d, dt;

    for(; !coada.empty(); ){
        d = coada.front(); coada.pop();
        for(int i = 0; i < 4; i++){
            dt = make_pair(d.first + di[i], d.second + dj[i]);
            if(ok(dt) && smen1[dt.first][dt.second] == 0 && smen[dt.first][dt.second] == 0)
                coada.push(dt), smen1[dt.first][dt.second] = smen1[d.first][d.second] + 1;
        }
    }

    return smen1[endd.first][endd.second];
}

int main(){
    cin>>n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin>>smen[i][j];

    query[0] = make_pair(1, 1);
    cin>>query[1].first>>query[1].second;
    cin>>query[2].first>>query[2].second;
    cin>>query[3].first>>query[3].second;
    query[4] = make_pair(n, n);

    int dist0A = Lee(query[0], query[1]),
        dist0B = Lee(query[0], query[2]),
        dist0C = Lee(query[0], query[3]),

        distAB = Lee(query[1], query[2]),
        distAC = Lee(query[1], query[3]),
        distBC = Lee(query[2], query[3]),

        distBA = distAB,
        distCA = distAC,
        distCB = distBC,

        distA4 = Lee(query[1], query[4]),
        distB4 = Lee(query[2], query[4]),
        distC4 = Lee(query[3], query[4]);


    int distABC = dist0A + distAB + distBC + distC4,
        distACB = dist0A + distAC + distCB + distB4,
        distBAC = dist0B + distBA + distAC + distC4,
        distBCA = dist0B + distBC + distCA + distA4,
        distCAB = dist0C + distCA + distAB + distB4,
        distCBA = dist0C + distCB + distBA + distA4;

    cout<<min(min(distABC, distACB), min(min(distBAC, distBCA), min(distCAB, distCBA)));
    return 0;
}
