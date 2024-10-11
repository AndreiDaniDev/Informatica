#include <fstream>
#include <stack>
using namespace std;
ifstream in("skyline.in");
ofstream out("skyline.out");
const int sizee = 40002;
///https://www.pbinfo.ro/probleme/2728/skyline
///https://www.pbinfo.ro/detalii-evaluare/52875498
int n, h[sizee], lf[sizee], rg[sizee]; 
int64_t sp[sizee], suprafata;
stack <int> st, dr;
int main(){
	in>>n;
    for(int i = 1; i <= n; i++)
        in>>h[i]>>sp[i], sp[i] += sp[i - 1];
    for(int i = 1; i <= n; i++){
    	for(; !st.empty() && h[i] <= h[st.top()]; st.pop());
        if(st.empty()) lf[i] = 1; else lf[i] = st.top() + 1;
        st.push(i);
    }
    for(int i = n; i >= 1; i--){
    	for(; !dr.empty() && h[i] <= h[dr.top()]; dr.pop());
        if(dr.empty()) rg[i] = n; else rg[i] = dr.top() - 1;
        suprafata = max(suprafata, (sp[rg[i]] - sp[lf[i] - 1]) * h[i]);
        dr.push(i);
    }
    out<<suprafata;
    return 0;
}
