#include <fstream>
using namespace std;
ifstream in("ssm.in");
ofstream out("ssm.out");
///https://www.infoarena.ro/problema/ssm
///https://www.infoarena.ro/job_detail/3239518
const int sizee = (1 << 6) - 1;
char bufferFastIO[sizee];
int indexIO = sizee - 1;

char nextChar(){
    indexIO += 1;
    if(indexIO == sizee)
        indexIO = 0, in.read(bufferFastIO, sizee);
    return bufferFastIO[indexIO];
}

int IO(){
    int val = 0; char t_; bool neg = false;
    for(t_ = nextChar(); isspace(t_); t_ = nextChar());
    for(neg = (t_ == '-');('0' <= t_ && t_ <= '9') || t_ == '-'; t_ = nextChar())
        if('0' <= t_ && t_ <= '9') val = 10 * val + t_ - '0';
    return val * ((neg) ? -1 : 1);
}

int n, x, sumMax = -(1 << 30), sum, st_ = 1, st, dr;
int main(){
    n = IO();
    for(int i = 1; i <= n; i++){
        x = IO();
        if(sum < 0)
            sum = 0, st_ = i;
        sum += x;
        if(sumMax < sum)
            sumMax = sum, st = st_, dr = i;
    }
    out<<sumMax<<" "<<st<<" "<<dr;
    return 0;
}
