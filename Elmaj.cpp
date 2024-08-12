#include <fstream>
using namespace std;
ifstream in("elmaj.in");
ofstream out("elmaj.out");
///https://www.infoarena.ro/problema/elmaj
///https://www.infoarena.ro/job_detail/3240033
const int sizee = (1 << 6);
char buffer[sizee];
int index = sizee - 1;

char next(){
    index++;
    if(index == sizee){
        index = 0;
        in.read(buffer, sizee);
    }
    return buffer[index];
}

int Get(){
    int x = 0; char t_; bool neg = false;
    for(t_ = next(); isspace(t_); t_ = next());
    for(neg = (t_ == '-');('0' <= t_ && t_ <= '9') || t_ == '-'; t_ = next())
        if('0' <= t_ && t_ <= '9') x = 10 * x + t_ - '0';
    return x * ((neg == 1) ? -1 : 1);
}

int n, v, p = -1, k, f;
int main(){
    n = Get();
    for(int i = 1; i <= n; i++){
        v = Get();
        if(k == 0){
            p = v;
            k = 1;
        }else if(v == p){
            k++;
        }else{
            k--;
        }
    }

    in.close(); in.open("elmaj.in"); index = sizee - 1;

    n = Get();
    for(int i = 1; i <= n; i++)
        v = Get(), f += (v == p);
    if(p > 0 && f >= (n / 2 + 1))
        out<<p<<" "<<f;
    else
        out<<-1;
    return 0;
}
