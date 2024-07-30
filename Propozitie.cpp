#include <fstream>
#include <string>
using namespace std;
ifstream in("propozitie.in");
ofstream out("propozitie.out");
///https://www.infoarena.ro/job_detail/3238727
int n, k, v[100002], sum[100002], dp; string s;
int main(){
    in>>n>>k>>s; sum[0] = 1;
    for(int i = 1; i <= s.size(); i++){
        if(s[i - 1] == 'a' || s[i - 1] == 'e' || s[i - 1] == 'i' || s[i - 1] == 'o' || s[i - 1] == 'u')
            v[++v[0]] = i;
        dp = (9001 + sum[i - 1] - ((v[0] > k) ? sum[v[v[0] - k] - 1] : 0)) % 9001;
        sum[i] = (9001 + sum[i - 1] + dp) % 9001;
    }
    dp = (9001 + sum[s.size()] - sum[s.size() - 1]) % 9001;
    out<<dp;
    return 0;
}
