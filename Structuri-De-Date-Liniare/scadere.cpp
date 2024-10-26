#include <fstream>
#include <string>
#include <stack>
using namespace std;
ifstream in("scadere.in");
ofstream out("scadere.out");
int task, n, v[5002], t, val = 0, x, y;;
///https://www.pbinfo.ro/probleme/1220/scadere
///https://www.pbinfo.ro/detalii-evaluare/53364266
char semn;
stack <int> num;
stack <char> op;
string s;

int calc(int x, int y, char z){
    if(z == '+') return x + y;
    if(z == '-') return x - y;
    return 0;
}

int grad(char z){
    if(z == '+') return 1;
    if(z == '-') return 1;
    return 0;
}

int main(){
    in>>task>>n;
    if(task == 1){
        in>>v[1]>>v[2];
        t = v[1] - v[2];
        for(int i = 3; i <= n; i++)
            in>>v[i], t += abs(v[i]);
        out<<t<<"\n";
        out<<"x1-";
        for(int i = 2, j; i <= n; i++){
            for(j = i; j <= n && v[j + 1] > 0; j++);
            if(j != i) out<<"(", val = 1;
            for(; i < j; i++) out<<"x"<<i<<"-";
            out<<"x"<<i;
            if(val) out<<")", val = 0;
            if(i != n) out<<"-";
        }
    }else{
        for(int i = 1; i <= n; i++)
            in>>v[i];
        in>>s;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'x'){
                i++, val = 0;
                for(; i < s.size() && ('0' <= s[i] && s[i] <= '9'); i++)
                    val = 10 * val + s[i] - '0';
                num.push(v[val]); i--;
            }else if(s[i] == '('){
                op.push(s[i]);
            }else if(s[i] == ')'){
                for(; !op.empty() && op.top() != '('; ){
                    y = num.top(); num.pop();
                    x = num.top(); num.pop();
                    semn = op.top(); op.pop();
                    num.push(calc(x, y, semn));
                }
                if(!op.empty()) op.pop();
            }else{
                for(; !op.empty() && grad(op.top()) >= grad(s[i]) && s[i] != '('; ){
                    y = num.top(); num.pop();
                    x = num.top(); num.pop();
                    semn = op.top(); op.pop();
                    num.push(calc(x, y, semn));
                }
                op.push(s[i]);
            }
        }
        for(; !op.empty(); ){
            y = num.top(); num.pop();
            x = num.top(); num.pop();
            semn = op.top(); op.pop();
            num.push(calc(x, y, semn));
        }
        out<<num.top();
    }
    return 0;
}
