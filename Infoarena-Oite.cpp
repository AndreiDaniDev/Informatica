#include <fstream>
#include <unordered_map>
using namespace std;
ifstream in("oite.in");
ofstream out("oite.out");
///https://www.infoarena.ro/job_detail/3235864
///https://www.infoarena.ro/problema/oite
int n, s, v[1024 + 2], comb;
unordered_map <int, int> m;
int main(){
    in>>n>>s; for(int i = 0; i < n; i++) in>>v[i];
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++)
            if(m.find(s - v[i] - v[j]) != m.end())
                comb += m[s - v[i] - v[j]];
        for(int j = 0; j < i; j++)
            m[v[i] + v[j]] += 1;
    }
    out<<comb;
    return 0;
}
