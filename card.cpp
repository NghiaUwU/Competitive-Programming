#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef string str;

const long long MOD = 998244353;
long long bigc[101];
long long dp[101][11];
long long mod1[101], mod2[101];
int factmod(int n, int p) {
    vector<int> f(p);
    f[0] = 1;
    for (int i = 1; i < p; i++)
        f[i] = f[i-1] * i % p;

    int res = 1;
    while (n > 1) {
        if ((n/p) % 2)
            res = p - res;
        res = res * f[n%p] % p;
        n /= p;
    }
    return res;
}

void precaculation(int n){
    bigc[0] = 1;
    mod1[0] = 1;
    mod2[0] = 1;
    for(int i = 1; i <= 60; i++){
        mod1[i] = ((mod1[i - 1] % MOD) * (i % MOD) % MOD )% MOD;
        mod1[i] = (mod1[i] * mod1[i]) % MOD;
    }
    for(int i = 1; i <= 60; i++)    mod2[i] = (mod2[i - 1] * i) % MOD;
    for(int i = 2; i <= 60; i+=2){
        bigc[i] = mod2[i] / mod1[i / 2];
        cout<<bigc[i]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    precaculation(n);
}