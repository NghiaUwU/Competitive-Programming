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
long long n;
            long long f[100005][4];
            void solve(){
                cin>>n;
                f[1][0] = 1;
                f[1][1] = 1;
                f[1][2] = 1;

                for(int i = 2; i <= n; i++){
                    for(int j = 0; j <= 2; j++){
                        if(j == 1)  f[i][j] = (f[i - 1][0] + f[i - 1][2]) % MOD;
                        else    f[i][j] = (f[i - 1][0] + f[i - 1][1] + f[i - 1][2]) % MOD;
                    }
                }

                cout<<(f[n][1] + f[n][2] + f[n][0] )% MOD;
            }

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        SOL GHL;
        solve();

    }