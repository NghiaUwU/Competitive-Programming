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
        long long mx[100006], a[100006], pre[100005];
        void solve(){
            cin>>n;
            for(int i = 1; i <= n; i++){
                cin>>a[i];
                pre[i] = pre[i - 1] + a[i];
            }

            long long ans = 0;
            long long sum = 0;

            mx[n + 1] = 0;
            for(int i = n; i >= 1; i--){
                sum = max(0LL, sum + a[i]);
                mx[i] = max(mx[i + 1], sum);
            }

            for(int i = 0; i <= n + 1; i++){
                ans = max(ans, pre[i] - (pre[n] - pre[i]) + mx[i + 1] * 2);
            }
            cout<<ans;

        }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

}