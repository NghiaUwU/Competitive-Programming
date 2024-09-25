#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

#define maximize(a, b) a = max(a, b)
#define minimize(a, b) a = min(a, b)

#define testBit(a, k) ((a >> k) & 1)
#define flipBit(a, k) (a ^ (1ll << k))

const int mxN = 16; 
class Solution{
   
    public:
        void solve(){
        ll n;
        cin>>n;
        vector<vector<int> > a(n + 1, vector<int>(n + 1));
        int dp[n + 1][1 << n];  

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                cin>>a[i][j];

        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++ i)
            for(int mask = 0; mask < (1 << n); ++ mask)
                for(int b = 0; b < n; ++ b)
                    if(mask >> b & 1)
                        dp[i][mask] = max(dp[i - 1][mask & ~(1 << b)] + a[i][b + 1], dp[i][mask]);
            
        cout<<dp[n][(1 << n) - 1];
    } 
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;
    Solution way;
    for(int i = 1; i <= test; i++){
        cout<<"Case "<<i<<": ";
        way.solve();
        cout<<endl;
    }

}