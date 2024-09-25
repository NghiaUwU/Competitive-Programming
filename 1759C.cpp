#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

class Solution{
    public:
        long long l, r, x;
        long long a, b;

        
        void solve(){
            kill_dependency(l);
            kill_dependency(r);
            kill_dependency(x);

            cin>>l>>r>>x;
            cin>>a>>b;
            if(a == b){
                cout<<'0'<<"\n";
                return;
            }
                
            if(abs(a - b) >= x){
                cout<<'1'<<"\n";
                return;
            }
                
            if(abs(a - r) >= x && abs(r - b) >= x){
                cout<<'2'<<"\n";
                return;
            }
                
            if(abs(a - l) >= x && abs(l - b) >= x){
                cout<<'2'<<"\n";
                return;
            }
                
            if(abs(a - r) >= x && abs(r - l) >= x && abs(l - b) >= x){
                cout<<"3"<<"\n";    
                return;
            }
            if(abs(a - l) >= x && abs(l - r) >= x && abs(r - b) >= x){
                cout<<"3"<<"\n";
                return;
            }
                
            else    cout<<"-1"<<endl;
            return;
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