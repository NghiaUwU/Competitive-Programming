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

struct storge{
    long long x, y, limt;
};
bool comper(storge a, storge b){
    return a.x < b.x;
}

storge t[10005];
int n;

long long dp[10004];

void solve(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>t[i].x>>t[i].y;
        t[i].limt = t[i].y - t[i].x;
    }
    
    /*
    time_t curr_time;
    curr_time = time(NULL);
    cout<<curr_time<<'\n';
    */
    sort(t + 1, t + 1 + n, comper);
    
    for(int i = 1; i <= n; i++){
        dp[i] = t[i].limt;
    }

    for(int i = 1; i <= n; i++){

        
        for(int j = 1; j < i; j++){
            if(t[i].x >= t[j].y){
                dp[i] = max(dp[i], dp[j] + t[i].limt);
            }
        }   
    }

    long long ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);

    cout<<ans<<'\n';
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

}