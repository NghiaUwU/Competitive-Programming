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
        vector < pair <long long, long long> > stk;

        long long a[100005];
        long long mn = 1e18, mx = 0;
        long long ans = 1e18;
        void solve(){
            cin>>n;
            
            for(int i = 1; i <= n; i++){
                cin>>a[i];
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
            }

            for(int i = 1; i <= n; i++)
                if(a[i] == mn || a[i] == mx)
                    stk.push_back({a[i], i});
            
            for(int i = 0; i < stk.size() - 1; i++){

                //cout<<stk[i].first<<' '<<stk[i + 1].first<<'\n';
                if(stk[i].first != stk[i + 1].first){
                    ans = min(ans, stk[i + 1].second - stk[i].second + 1);
                }
            }

            cout<<ans;
        }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    solve();

}