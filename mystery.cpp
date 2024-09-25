#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const long long MOD = 20122007;
long long POWMOD(long long a, long long b, ll mod){
    if(b == 0)  return 1;
    if(b == 2)  return ((a % mod) * (a % mod)) % mod;

    if(b % 2 != 0)  return ((a % mod) * (POWMOD(a, b - 1, mod) % mod) % mod);
    else    return ((POWMOD(a, b / 2, mod) % mod) * (POWMOD(a, b / 2, mod) % mod)) % mod;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin>>n;
    long long tich = 1;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            if(i * i == n){
                tich = (tich % MOD) * ((POWMOD(3, i, MOD) - 1) % MOD);
                tich %= MOD;
            }
            else{
                tich = (tich % MOD) * ((POWMOD(3, i, MOD) - 1) % MOD);
                tich %= MOD;
                tich = (tich % MOD) * ((POWMOD(3, n / i, MOD) - 1) % MOD);
                tich %= MOD;
            }
        }
    }
    cout<<tich;
}