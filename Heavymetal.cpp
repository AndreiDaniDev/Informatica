#include <fstream>
#include <utility>
#include <algorithm>
using namespace std;
ifstream in("heavymetal.in");
ofstream out("heavymetal.out");
///https://www.infoarena.ro/problema/heavymetal
///https://www.infoarena.ro/job_detail/3239610
typedef pair <int, int> pii;
int n, durata, t[100002];
pii intervale[100002];

bool sortPii(pii a, pii b){
    return a.second < b.second;
}

int main(){
    in>>n;
    for(int i = 1; i <= n; i++)
        in>>intervale[i].first>>intervale[i].second;
    sort(intervale + 1, intervale + 1 + n, sortPii);
    for(int i = 1, j = 1; i <= intervale[n].second; i++){
        t[i] = t[i - 1];
        for(; i == intervale[j].second; )
            t[i] = max(t[i], t[intervale[j].first] + intervale[j].second - intervale[j].first), j++;
    }
    out<<t[intervale[n].second];
    return 0;
}
