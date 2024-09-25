#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long ghl = 15052007;
const long long anniversary = 11102022;
const string every_second_with_you = "esctasy";

const long long MOD= 1e9 + 7;
int n;
ll storage[200005], pre[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>storage[i];
        pre[i] = (pre[i - 1] % MOD) + (storage[i] % MOD) % MOD;
        pre[i] %= MOD;
    }
    ll ans = 0, sum = 0;
    for(int i = 1; i < n; i++){
        sum = (((pre[n] + MOD) % MOD) - (pre[i] % MOD)) % MOD;
        ans = (ans % MOD) + ((storage[i] % MOD) * (sum % MOD) % MOD) % MOD;
    }
    ans = 0, sum = 0;
    for(int i = 1; i <= n; i++){
        ans = (ans % MOD) + ((storage[i] % MOD) * (sum % MOD) % MOD) % MOD;
        sum = (sum % MOD + storage[i] % MOD) % MOD;
    }
    cout<<ans;
}