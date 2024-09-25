#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long n, k, ans = 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    k = __builtin_popcount(n);

    for(int i = 1; i <= k; i++){
        ans *= 3;
        ans %= MOD;
    }

    cout<<ans;
}