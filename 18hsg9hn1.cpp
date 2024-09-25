#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

class SOL{
    public:
        long long n;
        bool prime(long long n){
            if(n <= 1)   return false;
            for(int i = 2; i * i <= n; i++){
                if(n % i == 0)  return false;
            }
            return true;
        }
        int sum(long long n){
            int tong = 0;
            while(n != 0){
                tong += (n % 10) * (n % 10);
                n /= 10;
            }

            return tong;
        }

        void solve(){
            cin>>n;
            n++;
            while(!prime(sum(n)))   n++;

            cout<<n;
        }
    
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("CAU1.inp", "r", stdin);
    freopen("CAU1.out", "w", stdout);
    SOL GHL;
    GHL.solve();
}