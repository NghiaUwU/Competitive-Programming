#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SOL{
    public:
        long long k;

        bool isPrime(long long n){
            if(n <= 1)  return false;
            for(int i = 2; i * i <= n; i++){
                if(n % i == 0)  return false;
            }
            return true;
        }
        void solve(){
            cin>>k;

            cout<<k - 1<<'\n';
        }
};

SOL GHL;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;

    cin>>test;

    while(test--){
        GHL.solve();
    }

}