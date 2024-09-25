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


long long f[10005], dp[10005], a[100005], n;

long long sum = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        sum += a[i];
    }
    memset(f, 0, sizeof(f));
    //memset(dp, );

    long long len = 0, mxval = 0;  
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] <= a[i]){
                if(f[j] + 1 >= f[i]){
                    if(f[j] + 1 == f[i])    dp[i] = max(dp[i], dp[j] + a[i]);
                    else    dp[i] = dp[j] + a[i];

                    f[i] = f[j] + 1;
                }
            }

            if(f[i] >= len){
                if(len == f[i]) mxval = max(mxval, dp[i]);
                else    mxval = dp[i];

                len = f[i];
            }
        }
    }

    cout<<sum - mxval;


}