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
long long picked[1000006];
long long matrix[1003][1003];
vector <ll> pick, test;
int n ,m;
long long dp[1005][1005];
//long long doop[1000006];
long long ans = 0;
void maximize(){

    for(int i = 0; i < pick.size(); i++)   test.push_back(pick[i]);
    sort(test.begin(), test.end());

    ans = max(ans, test[(pick.size() + 1) / 2 - 1]);
    
}

void dq(int x, int y, int sz){
    if(x == n && y == m){
        pick.push_back(matrix[x][y]);
        maximize();
        pick.pop_back();
        test.clear();
    }

    else{
        pick.push_back(matrix[x][y]);
        if(y + 1 <= m)  dq(x, y + 1, sz + 1);

        if(x + 1 <= n)  dq(x + 1, y, sz + 1);
        
        pick.pop_back();
    }
}
bool dyp(int k){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            // WATCH THE STEPS
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if(matrix[i][j] >= k)   dp[i][j]++;
        }
    }
    // ENOUGH STEp
    return (dp[n][m] * 2 >= n + m)? true : false;
}
void maxx(long long a, long long b){
    a = max(a, b);
}

void solve(){
    cin>>n>>m;
    if(n){
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin>>matrix[i][j];
        if(n <= 10 && m <= 10)  dq(1, 1, 1);
        else{
        long long ans = 0;
        //picked[1] = matrix[1][1];
        int l = 1, r = n * m;
        while(l <= r){
            int mid = (l + r)  / 2; 
            if(dyp(mid)){
                maxx(ans, mid);
                l = mid + 1;
            }
            else    r = mid - 1;
        }
        }
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

}

// ~~ * ~~ * ~~ *  ~~ *  ~~ * ~~ * //