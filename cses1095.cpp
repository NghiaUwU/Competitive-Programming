// CSES : Exponentiation

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

const long long MOD = 1e9 + 7;
class Solution{
    public:
        long long a, b;
        long long db(long long x){
            return x * x;
        }
        long long powMOD(long long a, long long b, long long mod = MOD){
            if(b == 0)  return 1 % mod;
            else{
                if(b % 2 == 0)  return db(powMOD(a, b / 2)) % mod;
                else    return a * (db(powMOD(a, b / 2)) % mod) % mod;
            }
        }
        void solve(){
            cin>>a>>b;
            cout<<powMOD(a, b)<<endl;
        }
         
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;

    while(test--){
        Solution GHL;
        GHL.solve();
    }
}