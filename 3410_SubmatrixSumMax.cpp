#include <iostream>
using namespace std;
int n, sp[302][302], sm = -(1 << 30), sm_ = -(1 << 30), s_ = 0;
///https://www.pbinfo.ro/probleme/3410/submatrixsummax
///https://www.pbinfo.ro/detalii-evaluare/51527612
int main(){
    cin>>n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin>>sp[i][j], sp[i][j] += sp[i - 1][j];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            sm_ = -(1 << 30); s_ = 0;
            for(int k = 1; k <= n; k++){
                s_ += (sp[i][k] - sp[j - 1][k]);
                sm_ = max(s_, sm_);
                s_ = (s_ < 0) ? 0 : s_;
            }
            sm = max(sm, sm_);
        }
    }
    cout<<sm;
    return 0;
}
