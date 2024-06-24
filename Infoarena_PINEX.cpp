#include <fstream>
#include <vector>
#include <bitset>
using namespace std;
ifstream in("pinex.in");
ofstream out("pinex.out");
int64_t a, b, m; const int64_t dimCiur = 1000002;
bitset <dimCiur> ciur; vector <int64_t> prime({2}), bfs;
///https://www.infoarena.ro/job_detail/3235947
void ciurulet(){
    for(int64_t i = 3; i * i < dimCiur; i += 2){
        if(!ciur[i])
            for(int64_t it = i * i; it < dimCiur; it += i)
                ciur[it] = 1;
    }
    for(int64_t i = 3; i < dimCiur; i += 2)
        if(!    ciur[i]) prime.push_back(i);
}

int64_t solve(){
    bfs.clear(); int64_t neprime = 0, sub = 0, dfs = 1;
    for(int64_t it = 0; it < prime.size() && prime[it] * prime[it] <= b; it++){
        if(!(b % prime[it])){
            bfs.push_back(prime[it]);
            for(; !(b % prime[it]); b /= prime[it]);
        }
    }
    if(b > 1) bfs.push_back(b);
    /*for(int64_t i = 0; i < bfs.size(); i++)
        out<<bfs[i]<<" "; out<<"\n";*/

    for(int64_t it = 1; it < (1 << bfs.size()); it++){
        sub = 0; dfs = 1;
        for(int64_t i = 0; i < bfs.size(); i++)
            if(it & (1 << i)) sub++, dfs *= bfs[i];
        //((sub & 1)) ? neprime += (a / dfs) : neprime (a / dfs);
        neprime += ((a / dfs) * (((sub & 1)) ? 1 : -1));
    }

    return a - neprime;
}

int main(){
    ciurulet(); in>>m; for(int64_t i = 0; i < m; i++) in>>a>>b, out<<solve()<<"\n";
    return 0;
}
