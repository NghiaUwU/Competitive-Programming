#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SOL{
    public:
        ll n, l;
        const long long MOD = 1e9 + 7;
        const int TWO_MOD_INV = 500000004;
        long long sum(long long l, long long r){
            return ((((((l + r) % MOD) * ((r - l + 1) % MOD) % MOD) % MOD) * TWO_MOD_INV) + MOD) % MOD;
        }
        long long DIV(long long n){
            
            long long s1 = 0, s2 = 0;
            long long tmp = sqrt(n);    

            for(int i = 1; i <= tmp ; i++){
                s1 += ((i ) * ((n / i - tmp)) + MOD ) % MOD;
                s1 += MOD;
                s1 %= MOD;
            }
            for(int i = 1; i <= tmp ; i++){
                s2 += (sum(1, n / i) + MOD) % MOD;
                s2 += MOD;
                s2 %= MOD;
            }

            long long ans = (s1 + s2 + MOD) % MOD ;
            
            return ans;
        }
        void solve(){
            
            cin>>l>>n;
            if(l == n){
                cout<<DIV(n);
            }
            else    cout<<((DIV(n) - DIV(l - 1)) + MOD) % MOD;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL P;
    P.solve();
}
