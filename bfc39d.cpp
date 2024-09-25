#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MOD = 1e9 + 7;
long long f[10005];

ll catalan(ll n)
{
    if (n <= 1)
        return 1;
    if(f[n] != 0)   return f[n];
    ll res = 0;
    for (int i = 0; i < n; i++){
        res += (catalan(i) % MOD * catalan(n - i - 1) % MOD) % MOD;
        res %= MOD;
    }
        
    f[n] = res;
    return res;
}
 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout << catalan(n) << '\n';
    }
        
    //return 0;
}