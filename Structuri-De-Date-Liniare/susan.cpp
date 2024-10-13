#include <fstream>
#include <queue>
using namespace std;
ifstream in("turn.in");
ofstream out("turn.out");
///LEE Tridimensional (in spatiu)
const int sizee = 102, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
struct triplet{ int x, y, z; } d, dt, comoara;
int n, ziduri, scariSus, scariJos, gropi, lee[sizee][sizee][sizee];
short cost[sizee][sizee][sizee]; queue <triplet> q;
/** Verticala - X
Orizontala1 - Y
Orizontala2 - Z **/
///https://www.pbinfo.ro/probleme/1337/susan
///https://pbinfo.ro/detalii-evaluare/52931113
bool ok(triplet a){
    return (
        1 <= a.x && a.x <= n &&
        1 <= a.y && a.y <= n &&
        1 <= a.z && a.z <= n
    );
}

void put(triplet a, int dist, int vali){
    if(ok(a) && cost[a.x][a.y][a.z] != 1 && !lee[a.x][a.y][a.z])
        q.push(a), lee[a.x][a.y][a.z] = dist + vali;
}

void Lee(triplet startingPoint){
    put(startingPoint, 0, 1);
    for(; !q.empty(); ){
        d = q.front(); q.pop();
        if(cost[d.x][d.y][d.z] == 2){
            dt = d, dt.x++; put(dt, 1, lee[d.x][d.y][d.z]);
        }else if(cost[d.x][d.y][d.z] == 3){
            dt = d, dt.x--; put(dt, 1, lee[d.x][d.y][d.z]);
        }else if(cost[d.x][d.y][d.z] == 4){
            for(dt = d; (ok(dt) && (cost[dt.x][dt.y][dt.z] == 4)); dt.x--);
            put(dt, d.x - dt.x, lee[d.x][d.y][d.z]);
        }else if(cost[d.x][d.y][d.z] == 0){
            for(int i = 0; i < 4; i++){
                dt.x = d.x;
                dt.y = d.y + dx[i];
                dt.z = d.z + dy[i];
                put(dt, 1, lee[d.x][d.y][d.z]);
            }
        }
    }
}

int main(){
    in>>n>>ziduri>>scariSus>>scariJos>>gropi;
    for(int i = 1; i <= ziduri; i++){
        ///Blocat
        in>>d.x>>d.y>>d.z;
        cost[d.x][d.y][d.z] = 1;
    }
    for(int i = 1; i <= scariSus; i++){
        ///Scara sus
        in>>d.x>>d.y>>d.z;
        cost[d.x][d.y][d.z] = 2;
    }
    for(int i = 1; i <= scariJos; i++){
        ///Scara jos
        in>>d.x>>d.y>>d.z;
        cost[d.x][d.y][d.z] = 3;
    }
    for(int i = 1; i <= gropi; i++){
        ///Groapa
        in>>d.x>>d.y>>d.z;
        cost[d.x][d.y][d.z] = 4;
    }
    in>>d.x>>d.y>>d.z>>comoara.x>>comoara.y>>comoara.z; Lee(d);
    /** O abordare pt mai multe lee-uri este sa precalculez
    pt. fiecare groapa unde ajunge player-ul **/
    out<<lee[comoara.x][comoara.y][comoara.z]<<"\n";
    return 0;
}
