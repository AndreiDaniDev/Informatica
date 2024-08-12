#include <fstream>
#include <string>
using namespace std;
ifstream in("edist.in");
ofstream out("edist.out");
///https://www.infoarena.ro/problema/edist
///https://www.infoarena.ro/job_detail/3240040
string s, t; int n, m, k, mini, maxi;
int64_t dp[2][20002];
int main(){
    in>>n>>m>>k>>s>>t;
    for(int j = 1; j <= t.size(); j++) dp[0][j] = j;

    for(int i = 1; i <= s.size(); i++){
        dp[i & 1][0] = i; mini = min((int)t.size(), i + k); maxi = max(1, i - k);
        for(int j = maxi; j <= mini; j++){
            dp[i & 1][j] = min(1 + min(dp[(i - 1) & 1][j], dp[i & 1][j - 1]),
                               dp[(i - 1) & 1][j - 1] + (s[i - 1] != t[j - 1]));
        }
    }
    out<<dp[s.size() & 1][t.size()];
    return 0;
}
