#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const long long GiaHanLe = 150507;

class Sol{
    public:
        long long n;
        
        long long dp[20][180][2];
 
        void takeDigit(ll x,vector<ll> &digits){
            if(x==0) digits.push_back(0);
            while(x){
                digits.push_back(x%10);
                x/=10;
            }
        }

        long long count(int idx, int sum, int tight, vector <ll> &digit){
            if(idx == -1)   return sum;
            if(dp[idx][sum][tight] != -1 && !tight) return dp[idx][sum][tight];

            long long res = 0;
            int k = (tight == 1) ? digit[idx] : 9;
            
            for(int i = 0; i <= k; ++i){
                res += count(idx - 1, sum + i, (digit[idx] == i) ? tight : 0, digit);
            }
            if(!tight)  dp[idx][sum][tight] = res;
            return res;
        }

        void solve(){
            long long a, b;
            cin>>a>>b;
            memset(dp, -1, sizeof(dp));
            vector <ll> digitA, digitB;
            takeDigit(a - 1, digitA);
            takeDigit(b, digitB);

            cout<<count(digitB.size() - 1, 0, 1, digitB) - count(digitA.size() - 1, 0, 1, digitA)<<"\n";
            
        }
};
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test;
    cin>>test;
    while(test--){
        Sol GHL;
        GHL.solve();
    
    }
}