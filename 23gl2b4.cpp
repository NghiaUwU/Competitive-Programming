#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long ghl = 15052007;
const long long anniversary = 11102022;
const string every_second_with_you = "esctasy";

const long long MOD = 1e9;

long long POWMOD(long long a, long long b, ll mod = MOD){
    if(b == 0)  return 1;
    if(b == 2)  return ((a % mod) * (a % mod)) % mod;

    if(b % 2 != 0)  return ((a % mod) * (POWMOD(a, b - 1, mod) % mod) % mod);
    else    return ((POWMOD(a, b / 2, mod) % mod) * (POWMOD(a, b / 2, mod) % mod)) % mod;

}

int n;
ll ans = 0;
ll a[100005], b[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(fopen("MUL.INP", "r")){
        freopen("MUL.INP", "r", stdin);
        freopen("MUL.OUT", "w", stdout);
    }
    cin>>n;
    for(int i =1; i <= n; i++)  cin>>a[i];
    for(int i =1; i <= n; i++)  cin>>b[i];

    for(int i =1; i <= n; i++){
        ans += POWMOD(a[i], b[i]);
        ans % MOD;
    }

    cout<<ans;

}
