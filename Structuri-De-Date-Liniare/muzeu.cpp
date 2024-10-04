#include <fstream>
#include <utility>
#include <queue>
#define x first
#define y second
using namespace std;
ifstream in("muzeu.in");
ofstream out("muzeu.out");
typedef pair <int, int> pii;
const int sizee = 252;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, lee[sizee][sizee];
queue <pii> q; pii d, dt;
char c; ///https://www.infoarena.ro/job_detail/3246943
bool ok(pii a){
    return 1 <= a.x && a.x <= n && 1 <= a.y && a.y <= n;
}
void Lee(){
    for(; !q.empty(); ){
        d = q.front(); q.pop();
        for(int k = 0; k < 4; k++){
            dt = make_pair(d.x + dx[k], d.y + dy[k]);
            if(ok(dt) && lee[dt.x][dt.y] > 1 + lee[d.x][d.y])
                lee[dt.x][dt.y] = 1 + lee[d.x][d.y], q.push(dt);
        }
    }
}

int main(){
    in>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            in>>c; lee[i][j] = (c == '#') ? -2 : (1 << 30);
            if(c == 'P') q.push(make_pair(i, j)), lee[i][j] = 0;
        }
    }
    Lee();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            lee[i][j] = (lee[i][j] == (1 << 30) ? -1 : lee[i][j]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            out<<lee[i][j]<<" ";
        out<<"\n";
    }
    return 0;
}
