#include <fstream>
#include <deque>
#include <utility>
#define x first
#define y second
using namespace std;
ifstream in("alee.in");
ofstream out("alee.out");
const int sizee = 177, costmax = (1 << 30);
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
typedef pair <int, int> pii;
int n, m, lee[sizee][sizee];
deque <pii> dq; pii startt, finishh, d, dt;
///https://www.pbinfo.ro/probleme/2167/alee
///https://www.pbinfo.ro/detalii-evaluare/52397248
///https://www.infoarena.ro/job_detail/3245454
bool ok(pii a){
    return 1 <= a.x && a.x <= n && 1 <= a.y && a.y <= n;
}
void Lee(){
    lee[startt.x][startt.y] = 1;
    dq.push_front(startt);
    for(; !dq.empty(); ){
        d = dq.back(); dq.pop_back();
        for(int i = 0; i < 4; i++){
            dt = make_pair(d.x + dx[i], d.y + dy[i]);
            if(ok(dt) && lee[dt.x][dt.y] > lee[d.x][d.y] + 1){
                lee[dt.x][dt.y] = lee[d.x][d.y] + 1;
                dq.push_front(dt);
            }
        }
    }
}

int main(){
    in>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            lee[i][j] = costmax;
    }
    for(int i = 1; i <= m; i++)
        in>>d.x>>d.y, lee[d.x][d.y] = -1;
    in>>startt.x>>startt.y;
    in>>finishh.x>>finishh.y; Lee(); 
    out<<lee[finishh.x][finishh.y]<<"\n";
    return 0;
}
