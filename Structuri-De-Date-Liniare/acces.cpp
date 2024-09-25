#include <fstream>
#include <utility>
#include <deque>
#define x first
#define y second
using namespace std;
ifstream in("acces.in");
ofstream out("acces.out");
const int sizee = 1002, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
typedef pair <int, int> pii; 
int n, m, lee[sizee][sizee];
pii d, dt; deque <pii> dq; 
char chr;
///https://www.pbinfo.ro/probleme/866/acces
///https://www.pbinfo.ro/detalii-evaluare/52296798
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
            in>>chr; lee[i][j] = ((chr == '#') ? -1 : (1 << 30));
            if(chr == 'P') lee[i][j] = 0, dq.push_front(make_pair(i,j));
        }
    }
    genLee();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            lee[i][j] = ((lee[i][j] == (1 << 30)) ? -1 : lee[i][j]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            out<<lee[i][j]<<" ";
        out<<"\n";
    }
    return 0;
}
