#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long ghl = 15052007;
const long long anniversary = 11102022;
const string every_second_with_you = "esctasy";

class SOL{
    public:
        ll n;
        void solve(){
            cin>>n;
            if(n == 0)  cout<<1;
            else if(n == 1)  cout<<5;
            else cout<<4 * n + 1 + (n - 1) * n * 2;   
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    SOL GHL;
    GHL.solve();
}