#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

//  ~~ * ~~ NGHIA HAS GH ~~ * ~~ //
//  ~~ * ~~ NGHIA belongs to GHL ~~ * ~~

const long long ghl = 15052007;
const long long anniversary = 11102022;
const bool i_love_you_so_much = true; 
const long long MOD = 1e9 + 7;
const long long MAX = 1e18;

// ~~ * ~~ * ~~ *  ~~ *  ~~ * ~~ * //


class SOL{
    public:
        
};
int n;
        long long h[100006];
        long long mx[100006], mn[100006];
        
        bool decrease = true;
        void solve(){
            cin>>n;
            for(int i = 1; i <= n; i++){
                cin>>h[i];
                if(i != 1 && h[i] > h[i - 1])   decrease = false;
            }

            if(decrease == true){
                cout<<"-1";
                return;
            }
            for(int i = n; i >= 1; i--)
                mx[i] = max(mx[i + 1], h[i]);
            
            int l, r, ans = 0, c;
            for(int i = 1; i <= n - 1; i++){
                l = i + 1, r = n;
                c = -1;
                while(l <= r){
                    int mid = (l + r) / 2;
                    if(h[i] < mx[mid]){
                        c = mid;
                        l = mid + 1;
                    }
                    else    r = mid - 1;
                }
                //cout<<c;
                if(c != -1) ans = max(ans, c - i);
            }
            
            cout<<ans;

        }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    solve();

}