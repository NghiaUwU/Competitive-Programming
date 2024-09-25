#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long maximize(ll a, ll b){
    if(a >= b)  return a;
    else    return b;
}
long long minimum(ll a, ll b){
    if(a <= b)  return a;
    else    return b;
}
ll read(){ll n; cin>>n; return n;}
string readstr(){string s; cin>>s; return s;}
vector <ll> dff;
void print(int a){
    cout<<a<<endl;
    return;
}
int a[100005];
int b[100005];
int dp[100005];
string c, d;
void solving(){

        ll n, k, y, ans = 0, res = 0, t = 0;
        kill_dependency(n);
        kill_dependency(k);
        kill_dependency(y);
        dff.clear();
        n = read();
        k = read();
        y = read();
        memset(a, 0, n);
        c = readstr();
        d = readstr();

        for(int i = 0; i <= c.size() - 1; i++){
            if(c[i] != d[i] || d[i] != c[i])    dff.push_back(i);
        }   
        if(dff.empty()){
            cout<<0<<endl;
            return;
        }
        else if(dff.size() % 2 != 0){
            cout<<"-1"<<endl;
            return;
        }
        else if(dff.size() > 2){
            cout<<(dff.size() / 2 )* y<<endl;
            return;
        }
        else if(dff[0] + 1 == dff[1]){
            cout<<min(k, y * 2)<<endl;
            return;
        }
        
        
        

        

        
        else    cout<<y<<endl;
        kill_dependency(k);        
        return;



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    kill_dependency(test);
    cin>>test;
    while(test--){
        solving();
    }
}
