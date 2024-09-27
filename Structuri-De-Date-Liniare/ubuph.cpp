#include <fstream>
#include <utility>
#include <queue>
#define x first
#define y second
using namespace std;
ifstream in("ubuph.in");
ofstream out("ubuph.out");
typedef pair <int, int> pii;
const int sizee = 1002, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int n, m, costuri[sizee][sizee], lee[sizee][sizee];
queue <pii> dq; pii d, dt, startt, endd;
///https://www.pbinfo.ro/probleme/1871/ubuph
///https://www.pbinfo.ro/detalii-evaluare/52364583
const int buffsize = (1 << 10) - 1;
char buff[buffsize]; int idx = buffsize - 1;

char nextchar(){
    idx++;
    if(idx == buffsize){
        idx = 0;
        in.read(buff, buffsize);
    }
    return buff[idx];
}

void get(int& val){
    char t_; val = 0; int sign = 1;
    for(t_ = nextchar(); isspace(t_); t_ = nextchar());
    if(t_ == '-') t_ = nextchar(), sign = -1;
    for(; '0' <= t_ && t_ <= '9'; t_ = nextchar())
        val = 10 * val + t_ - '0';
    val *= sign; return;
}

bool ok(pii a){
    return 1 <= a.x && a.x <= n && 1 <= a.y && a.y <= m;
}

void Lee(){
    for(; !dq.empty(); ){
        d = dq.front(); dq.pop();
        for(int i = 0; i < 4; i++){
            dt = make_pair(d.x + dx[i], d.y + dy[i]);
            if(ok(dt) && lee[dt.x][dt.y] > costuri[dt.x][dt.y] + lee[d.x][d.y])
                lee[dt.x][dt.y] = costuri[dt.x][dt.y] + lee[d.x][d.y], dq.push(dt);
        }
    }
}

int main(){
    get(n); get(m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            get(costuri[i][j]);
            lee[i][j] = (1 << 30);
        }
    }
    get(startt.x); get(startt.y); get(endd.x); get(endd.y);
    lee[startt.x][startt.y] = costuri[startt.x][startt.y]; 
    dq.push(startt); Lee();
    out<<lee[endd.x][endd.y];
    return 0;
}
