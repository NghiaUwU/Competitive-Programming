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

long long dp[21][1 << 20];
long long value[21][21];
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>value[i][j];
        }
    }  
    for(int i = 1; i <= n; i++){
        for(int mask = 0; mask < (1 << n); mask++){
            for(int b = 0; b < n; b++){
                if(mask >> b & 1){
                    dp[i][mask] = max(dp[i - 1][mask & ~(1 << b)] + value[i][b + 1], dp[i][mask]);
                }
            }
        }
    }
    cout<<dp[n][(1 << n) - 1];


}