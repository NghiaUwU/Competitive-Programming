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
int n, m;
        //long long occupy;
        int r[2002], x[2002];
        int occupied[2002];
        void solve(){
            cin>>n>>m;
            for(int i = 1; i <= m; i++){
                cin>>x[i]>>r[i];
            }

            for(int i = 1; i <= m; i++){
                int left = max(1, x[i] - r[i]);
                int right = min(x[i] + r[i], n);

                for(int j = left; j <= right; j++)  occupied[j] = 1;
            }           

            int cnt = 0;
            for(int i = 1; i <= n; i++){
                if(occupied[i] == 1)    cnt++;
            }

            cout<<cnt;
        }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

}