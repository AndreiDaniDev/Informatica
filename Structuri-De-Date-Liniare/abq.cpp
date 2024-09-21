#include <fstream>
#include <utility>
#include <queue>
#define x first
#define y second
using namespace std;
ifstream in("abq.in");
ofstream out("abq.out");
///https://www.pbinfo.ro/probleme/3114/abq
///https://www.pbinfo.ro/detalii-evaluare/51668940
typedef pair <int, int> pii;
int n, m, querys, lee; pii s, f, d, dt; char c;
int smen[202][202];bool dp[202][202];

const int dx[] = {-1, 0, 1, 0}; 
const int dy[] = {0, -1, 0, 1};

queue <pii> q;

bool ok(pii a){
    return 1 <= a.x && a.x <= n && 1 <= a.y && a.y <= m;
}

int Lee(pii startt, pii endd){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            smen[i][j] = 0;
    }
    
    q.push(startt);
    for(; !q.empty(); ){
        d = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            dt = make_pair(d.x + dx[i], d.y + dy[i]);
            if(ok(dt) && smen[dt.x][dt.y] == 0 && dp[dt.x][dt.y] == 0)
                q.push(dt), smen[dt.x][dt.y] = smen[d.x][d.y] + 1;
        }
    }
    
    return smen[endd.x][endd.y];
}
int main(){
    in>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            in>>c, dp[i][j] = ((c == 'a') ? 0 : 1);
    }
    
    in>>querys;
    for(int i = 1; i <= querys; i++){
        in>>s.x>>s.y>>f.x>>f.y;
        if(dp[s.x][s.y] || dp[f.x][f.y]){
            out<<"-1"<<"\n";
        }else{
            lee = Lee(s, f);
            out<<((lee == 0) ? -1 : lee + 1)<<"\n";
        }
    }
    return 0;
}
