#include <bits/stdc++.h>
using namespace std;

class SOL{
    public:
        char c;
        void solve(){
            cin>>c;
            if(c == 'c' || c == 'o' || c == 'd' || c == 'e' || c == 'f' || c == 's' || c == 'r'){
                cout<<"YES"<<'\n';
            }
            else    cout<<"NO"<<'\n';
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;
    while(test--){
        
        
    SOL GHL;
    GHL.solve();
    }
}