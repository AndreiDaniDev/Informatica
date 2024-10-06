#include <fstream>
#include <utility>
#include <queue>
#define x first
#define y second
using namespace std;
ifstream in("drum.in");
ofstream out("drum.out");
typedef pair <int, int> pii; pii d, dt;
const int sizee = 502, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int n, m, vmax, k, val, cost[sizee][sizee], lee[sizee][sizee];
int distmin, mini = (1 << 30), st, dr, mij, pos;
///https://www.pbinfo.ro/probleme/151/drum
///https://www.pbinfo.ro/detalii-evaluare/52667319
bool ok(pii a){
    return 1 <= a.x && a.x <= n && 1 <= a.y && a.y <= m;
}

int Lee(int costmax){
    queue <pii> q;
    for(int j = 1; j <= m; j++){
        if(cost[1][j] <= costmax){
            q.push(make_pair(1, j));
            lee[1][j] = costmax;
        }
    }
    for(; !q.empty(); ){
        d = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            dt = make_pair(d.x + dx[i], d.y + dy[i]);
            if(ok(dt) && lee[dt.x][dt.y] != costmax && cost[dt.x][dt.y] <= costmax){
                lee[dt.x][dt.y] = costmax, q.push(dt);
                if(dt.x == n) return 1;
            }
        }
    }
    return 0;
}

int main(){
    in>>n>>m>>vmax;
    for(int i = 1; i <= vmax; i++){
        in>>k;
        for(int j = 1; j <= k; j++){
            in>>val;
            d.x = ((val - 1) / m + 1);
            d.y = ((val % m) ? (val % m) : m);
            cost[d.x][d.y] = i;
        }
    }
    /*for(val = 1; val <= (n * m); val++){
        d.x = ((val - 1) / m + 1);
        d.y = ((val % m) ? (val % m) : m);
        cost[d.x][d.y] = val;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            out<<cost[i][j]<<" ";
        out<<"\n";
    }*/
    for(int j = 1; j <= m; j++)
        mini = min(mini, cost[1][j]);
    for(st = mini, dr = vmax; st <= dr; ){
        mij = (st + dr) >> 1;
        if(Lee(mij)){
            pos = mij, dr = mij - 1;
        }else{ st = mij + 1; }
    }
    out<<pos<<"\n";
    return 0;
}
