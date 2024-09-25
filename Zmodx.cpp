#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef string str;
typedef unsigned long long ull;

ll read(){ll n; cin>>n; return n;}

void solve(){
    ll a = read();
    ll b = read();
    ll c = read();
     cout<< a+b+c<<" "<<b + c<<" "<<c<<endl;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        solve();
    }
}