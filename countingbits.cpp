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
const long long MAX_BIT = 20;

// ~~ * ~~ * ~~ *  ~~ *  ~~ * ~~ * //
long long dp[51];
long long n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    dp[0] = 1;
    for(int i = 1; i <= 50; i++){
        dp[i] = dp[i - 1] * 2 + ((1LL << (i - 1)) - 1);
    }
    long long ans = 0;

    while(n > 0){
        long long b = log2(n);
        ans += dp[b];
        b = 1LL << b;
        ans += n - b;
        n -= b;
    }

    cout<<ans;
    
}