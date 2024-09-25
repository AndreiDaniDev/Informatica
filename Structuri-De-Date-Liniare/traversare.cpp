#include <fstream>
#include <utility>
#include <deque>
#define x first
#define y second
using namespace std;
ifstream in("traversare.in");
ofstream out("traversare.out");
const int sizee = 1002, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
typedef pair <int, int> pii; 
int n, m, lee[sizee][sizee], val;
pii d, dt; deque <pii> dq; 
///https://www.pbinfo.ro/probleme/883/traversare
///https://www.pbinfo.ro/detalii-evaluare/52297192
bool ok(pii a){
    return 1 <= a.x && a.x <= n && 1 <= a.y && a.y <= m;
}
void genLee(){
    for(; !dq.empty(); ){
        d = dq.front(); dq.pop_front();
        for(int i = 0; i < 4; i++){
            dt = make_pair(d.x + dx[i], d.y + dy[i]);
            if(ok(dt) && lee[dt.x][dt.y] > 1 + lee[d.x][d.y])
                lee[dt.x][dt.y] = 1 + lee[d.x][d.y], dq.push_back(dt);
        }
    }
}
int main(){
    in>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            in>>val; lee[i][j] = ((val == 1) ? -1 : (1 << 30));
            if(val == 0 && i == 1) lee[i][j] = 1, dq.push_front(make_pair(i,j));
        }
    }
    genLee(); val = (1 << 30);
    for(int j = 1; j <= m; j++){
        if(lee[n][j] != -1)
            val = min(val, lee[n][j]);
    }
    out<<val;
    return 0;
}
