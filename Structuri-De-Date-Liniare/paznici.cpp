#include <fstream>
#include <queue>
#include <utility>
#define x first
#define y second
using namespace std;
ifstream in("paznici.in");
ofstream out("paznici.out");
typedef pair <int, int> pii; char c;
const int sizee = 202, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int n, m, q, dist, lee[sizee][sizee], last[sizee][sizee], camere; queue <pii> qq; pii d, dt, pos;
///https://www.pbinfo.ro/probleme/884/paznici
///https://www.pbinfo.ro/detalii-evaluare/52397615
bool ok(pii a){
    return 1 <= a.x && a.x <= n && 1 <= a.y && a.y <= m;
}
void Lee(int distmax, int test){
    for(; !qq.empty(); ){
        d = qq.front(); qq.pop();
        for(int i = 0; i < 4; i++){
            dt = make_pair(d.x + dx[i], d.y + dy[i]);
            if(ok(dt) && last[dt.x][dt.y] != test && last[dt.x][dt.y] != -1){
                lee[dt.x][dt.y] = 1 + lee[d.x][d.y];
                last[dt.x][dt.y] = test;
                if(lee[dt.x][dt.y] < distmax) qq.push(dt);
            }
        }
    }
}
int main(){
    in>>n>>m>>q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            in>>c;
            if(c == '#'){
                lee[i][j] = -1;
                last[i][j] = -1;
            }else{
                lee[i][j] = (1 << 30);
            }
        }
    }
    for(int query = 1; query <= q; query++){
        in>>pos.x>>pos.y>>dist;
        lee[pos.x][pos.y] = 0;
        last[pos.x][pos.y] = query;
        qq.push(pos); Lee(dist, query);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            camere += (last[i][j] == 0);
    }
    out<<camere;
    return 0;
}
