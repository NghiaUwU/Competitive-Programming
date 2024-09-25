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
const long long ARR = 2e5;
// ~~ * ~~ * ~~ *  ~~ *  ~~ * ~~ * //



        string s;
        int cnt[32][ARR + 2];
        int ans = 0, n;

        bool check(int r){
            for(int l = 1; r <= n; l++, r++){
                int x = 0; 
                for(int i = 1; i <= 26; i++){
                    x = max(x, cnt[i][r] - cnt[i][l - 1]);
                    if(x * 2 > r - l + 1)   return true;
                }

            }
            return false;

        }
        void solve(){
            cin>>s;
            n = s.size();           
            s = " " + s;

            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= 26; j++)    cnt[j][i] = cnt[j][i - 1];
                cnt[s[i] - 'a' + 1][i]++;
            }

            int l = 1, r = n, ans = 1;

            while(l <= r){
                int mid = (l + r) / 2;
                if(check(mid)){
                    l = mid + 1;
                    ans = mid;
                }
                else    r = mid - 1;
            }
            cout<<ans;
        }



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

}