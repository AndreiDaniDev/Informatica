#include <fstream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
ifstream in("text.in");
ofstream out("text.out");

///https://www.pbinfo.ro/probleme/1093/text
///https://www.pbinfo.ro/detalii-evaluare/51611441
///https://kilonova.ro/submissions/405861

string s[20002], it; vector <int> sol;
int n, lmax, poss, lastPos['z' - 'a' + 2], dp[20002], previous[20002];

int main(){
	for(n = 1; in>>s[n]; n++); n--;

	for(int i = 1; i <= n; i++){
        it = s[i];
        dp[i] = dp[lastPos[it[0] - 'a']] + 1;
        previous[i] = lastPos[it[0] - 'a'];
        if(dp[i] > dp[lastPos[it[it.size() - 1] - 'a']])
            lastPos[it[it.size() - 1] - 'a'] = i;
	}

	for(int i = 1; i <= n; i++)
        if(lmax < dp[i])
            lmax = dp[i], poss = i;

    out<<n<<"\n"<<n - lmax<<"\n";

    sol.push_back(poss);
    poss = previous[poss];
    for(; poss; ){
        sol.push_back(poss);
        poss = previous[poss];
    }

    for(int i = sol.size() - 1; i >= 0; i--)
        out<<s[sol[i]]<<"\n";
	return 0;
}
