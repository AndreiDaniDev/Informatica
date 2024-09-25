#include <fstream>
#include <utility>
#include <queue>
#define x first
#define y second
using namespace std;
ifstream in("taxe2.in");
ofstream out("taxe2.out");
typedef pair <int, int> pii; pii d, dt;
int s, n, cost, costuri[202][202], dp[202][202];
///https://www.pbinfo.ro/probleme/1856/taxe2
///https://www.pbinfo.ro/detalii-evaluare/51671486
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

bool ok(pii a){ return 1 <= a.x && a.x <= n && 1 <= a.y && a.y <= n; }
int LeeCost(pii startt, pii endd){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            dp[i][j] = (1 << 30) - 1 + (1 << 30);
    }
    queue <pii> q; q.push(startt);
    dp[startt.x][startt.y] = costuri[startt.x][startt.y];
    for(; !q.empty(); ){
        d = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            dt = make_pair(d.x + dx[i], d.y + dy[i]);
            if(ok(dt)){
                if(dp[dt.x][dt.y] > dp[d.x][d.y] + costuri[dt.x][dt.y])
                    dp[dt.x][dt.y] = dp[d.x][d.y] + costuri[dt.x][dt.y], q.push(dt);
            }
        }
    }
    return dp[endd.x][endd.y];
}

int main(){
    in>>s>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            in>>costuri[i][j];
    }
    cost = LeeCost(make_pair(1, 1), make_pair(n, n));
    out<<((s >= cost) ? s - cost : -1);
    return 0;
}
