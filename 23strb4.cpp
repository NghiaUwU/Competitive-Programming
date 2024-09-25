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
        long long n, step[1003], a, b, x, y;
        long long pre[1003];
        long long ans = 0;
        void solve(){
            cin>>n>>a>>x>>b>>y;
            for(int i = 1; i <= a; i++) pre[i] = x;
            for(int i = 1; i <= b; i++) pre[i + a] = y;
            
            for(int i = 1; i <= n; i++) cin>>step[i];
            for(int i = 1; i <= a + b; i++) cout<<pre[i]<<' ';
            cout<<'\n';
            sort(pre + 1, pre + 1 + a + b);
            while(next_permutation(pre + 1, pre + 1 + a + b)){
                long long sum = 0;
                int stp = 0;
                for(int i = 1; i <= a + b; i++){
                    stp += pre[i];
                    sum += step[stp];
                }

                ans = max(ans, sum);
            }

            cout<<ans;
        }

};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();

}