#include <fstream>
#include <vector>
using namespace std;

ifstream in("masti-de-biti.in");
ofstream out("masti-de-biti.out");

void genSubmultimi(vector <int> v){
    int masti = (1 << v.size());
    for(int mask = 0; mask < masti; mask++){
        for(int i = 0; i < v.size(); i++)
            if(mask & (1 << i)) out<<v[i]<<" ";
        out<<"\n";
    }
}

int n, x; vector <int> v;
int main(){
    in>>n; v.resize(n);
    for(int i = 0; i < n; i++)
        in>>v[i];

    genSubmultimi(v);

    return 0;
}
