#include <fstream>
#include <vector>
#include <bitset>
using namespace std;

ifstream in("masti-de-biti.in");
ofstream out("masti-de-biti.out");

const int mastiBiti = 20;
bitset <mastiBiti> getBitset(int n){
    return bitset <mastiBiti> (n);
}

void genSubmultimi(vector <int> v){
    int masti = (1 << v.size());
    bitset <mastiBiti> biti;
    for(int mask = 0; mask < masti; mask++){
        biti = getBitset(mask);
        for(int i = 0; i < mastiBiti; i++)
            if(biti[i]) out<<v[i]<<" ";
        out<<"\n";
    }
}

int n, x; vector <int> v;
int main(){
    in>>n; v.resize(n);
    for(int i = 0; i < n; i++)
        in>>v[i];

    genSubmultimi(v);
    ///cout<<getBitset(n)[0];

    return 0;
}
