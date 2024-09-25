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
int n, k;
long long a[105];
pair <int, int> factor[105];
long long dp[105];    
void solve(){
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
            cin>>a[i];
        while(a[i] % 2 == 0){
            factor[i].first++;
            a[i] /= 2;
        }
        while(a[i] % 5 == 0){
            factor[i].second++;
            a[i] /= 5;
        }
    }
    
    for(int i = 1; i <= n; i++){
        
    }
            
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    solve();

}