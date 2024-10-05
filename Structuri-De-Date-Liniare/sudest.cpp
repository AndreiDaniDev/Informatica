#include <fstream>
#include <queue>
using namespace std;
ifstream in("sudest.in");
ofstream out("sudest.out");
///https://www.pbinfo.ro/probleme/1538/sudest
///https://www.pbinfo.ro/detalii-evaluare/52627848
///https://kilonova.ro/submissions/443793
const int sizee = 102;
const int dx[] = {1, 0}, dy[] = {0, 1};
struct pii{
    int x, y, idx;
} d, dt, moves[sizee << 1]; queue <pii> q;
int n, k, v[sizee << 1], lee[sizee][sizee], cost[sizee][sizee];
bool ok(pii a){
    return 1 <= a.x && a.x <= n && 1 <= a.y && a.y <= n;
}
void Lee(){
    for(; !q.empty(); ){
        d = q.front(); q.pop();
        if((d.x == n && d.y == n) || (d.idx > k))
            continue;
        for(int i = 0; i < 2; i++){
            dt.x = d.x + dx[i] * v[d.idx];
            dt.y = d.y + dy[i] * v[d.idx];
            if(ok(dt) && lee[dt.x][dt.y] < cost[dt.x][dt.y] + lee[d.x][d.y]){
                lee[dt.x][dt.y] = cost[dt.x][dt.y] + lee[d.x][d.y];
                dt.idx = d.idx + 1; q.push(dt);
            }
        }
    }
}
int main(){
    in>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            in>>cost[i][j];
    }
    in>>k;
    for(int i = 1; i <= k; i++)
        in>>v[i];
    lee[1][1] = cost[1][1]; q.push({1, 1, 1});
    Lee(); out<<lee[n][n]<<"\n";
    
    d.x = n, d.y = n, d.idx = k;
    for(; d.idx >= 1; ){
        for(int i = 0; i < 2; i++){
            dt.x = d.x - dx[i] * v[d.idx];
            dt.y = d.y - dy[i] * v[d.idx];
            dt.idx = d.idx - 1;
            if(lee[dt.x][dt.y] == lee[d.x][d.y] - cost[d.x][d.y])
                moves[d.idx] = dt, d = dt, i = 2;
        }
    }
    for(int i = 1; i <= k; i++)
        out<<moves[i].x<<" "<<moves[i].y<<"\n";
    out<<n<<" "<<n<<"\n";
    return 0;
}
