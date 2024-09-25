#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SOL{
    public:
        ll n, k;
        void solve(){
            cin>>n>>k;
            
            long long sum = n * (n + 1) / 2;
            k = abs(k);

            if(sum % 2 != k % 2 || k > sum){
                cout<<"NO"<<'\n';
            }
            else    cout<<"YES"<<'\n';
        }
};  

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while ((t--))
    {
        SOL GHL;
        GHL.solve();
    }
    

}