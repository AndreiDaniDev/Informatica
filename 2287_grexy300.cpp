#include <fstream>
using namespace std;
ifstream in("grexy.in");
ofstream out("grexy.out");
///https://www.pbinfo.ro/probleme/2287/grexy300
///https://www.pbinfo.ro/detalii-evaluare/51780496
const int sizee = (1 << 12);
int index = sizee - 1;
char buff[sizee];

char next(){
    index++;
    if(index == sizee){
        in.read(buff, sizee);
        index = 0;
    }
    return buff[index];
}

void get(int &x){
    x = 0; bool neg = 0; char t__;
    for(t__ = next(); isspace(t__); t__ = next());
    if(t__ == '-') neg = 1, t__ = next();
    for(; '0' <= t__ && t__ <= '9'; t__ = next())
        x = 10 * x + t__ - '0';
    x *= (neg ? -1 : 1);
    return;
}

int n, x, dp[100002];
int main(){
    /*
    ///dp[0][i] = cate cuvinte exista de lungime i
    ///dp[1][i] = cate cuvinte palindromice exista de lungime i
    dp[0][1] = 26; dp[1][1] = 26;
    for(int i = 2; i <= 100002; i++){
        dp[0][i] = (26 * dp[0][i - 1]) % 666013;
        dp[1][i] = (dp[0][(i + 1) / 2]) % 666013;
    }
    get(n);
    for(int i = 1; i <= n; i++)
        get(x), out<<(dp[0][x] - dp[1][x] +  666013) % 666013<<"\n";
    */
    dp[1] = 26;
    for(int i = 2; i < 100002; i++)
        dp[i] = (26 * dp[i - 1]) % 666013;
    get(n);
    for(int i = 1; i <= n; i++)
        get(x), out<<(dp[x] - dp[(x + 1) / 2] + 666013) % 666013<<"\n";
    return 0;
}
