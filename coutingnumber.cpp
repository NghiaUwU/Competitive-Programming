// CSES: COUNTING NUMBERS
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const long long GiaHanLe = 150507;

class Sol{
    public:
        long long n;
        
        long long dp[20][20][2][2];
 
        void takeDigit(ll x,vector<ll> &digits){
            if(x==0) digits.push_back(0);
            while(x){
                digits.push_back(x%10);
                x/=10;
            }
        }

        ll count(ll idx,ll tight, vector<ll> &digit,ll pre,bool zero){
            if(idx==-1){
                return 1;
            }
             if(dp[idx][tight][pre][zero]!=-1&&tight!=1) return dp[idx][tight][pre][zero];
            ll res=0;
            ll k=(tight) ? digit[idx] : 9;
            for(int i=0;i<=k;i++){
                if(!zero&&i==pre) continue;
                 res += count(idx-1,(digit[idx] == i) ? tight : 0,digit,i,(i==0&&zero) ? true : false);
             }

            if(!tight) dp[idx][tight][pre][zero]=res;
            return res;
        }

        void solve(){
            long long a, b;
            cin>>b;
            memset(dp, -1, sizeof(dp));
            vector <ll> digitA, digitB;
            //takeDigit(a - 1, digitA);
            takeDigit(b, digitB);

            cout<<count(digitB.size() - 1, 1, digitB, -1, true);
        }
};
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
        Sol GHL;
        GHL.solve();
    
    
}