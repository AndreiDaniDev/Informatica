#include <fstream>
#include <utility>
#include <queue>
#define x first
#define y second
using namespace std;
ifstream in("meteoriti.in");
ofstream out("meteoriti.out");
///https://www.pbinfo.ro/probleme/1461/meteoriti
///https://www.pbinfo.ro/detalii-evaluare/52925198
typedef pair <int, int> pii;
const int sizee = 2002, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int n, m, queries, val, smen[sizee][sizee], ariemax, maxi;
pii d, dt;

bool ok(pii a){
    return 1 <= a.x && a.x <= n && 1 <= a.y && a.y <= m;
}
int Fill(pii start, int vali){
    ///Puteam sa implementez si recursiv, dar
    ///aceasta varianta este mai usoara de implementat
    
    if(smen[start.x][start.y] != vali)
        return 0;
    
    queue <pii> q; q.push(start);
    int arieFill = 1;
    smen[start.x][start.y] = vali + 1;
    for(; !q.empty(); ){
        d = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            dt = make_pair(d.x + dx[i], d.y + dy[i]);
            if(ok(dt) && smen[dt.x][dt.y] == vali){
                smen[dt.x][dt.y] = vali + 1;
                arieFill++; q.push(dt);
            }
        }
    }
    return arieFill;
}

int main(){
    in>>n>>m>>queries;
    for(int i = 1; i <= queries; i++){
        in>>d.x>>d.y>>dt.x>>dt.y>>val;
        smen[d.x][d.y] += val;
        smen[d.x][dt.y + 1] -= val;
        smen[dt.x + 1][d.y] -= val;
        smen[dt.x + 1][dt.y + 1] += val;
    }
    
    val = 0; maxi = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            smen[i][j] += smen[i - 1][j] + smen[i][j - 1] - smen[i - 1][j - 1];
        
            val += (smen[i][j] == 0);
            maxi = max(maxi, smen[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            ariemax = max(ariemax, Fill(make_pair(i, j), maxi));
    }
    out<<ariemax<<" "<<val;
    return 0;
}
