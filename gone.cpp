#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

long long read(){ll n; cin>>n; return n;}
class SOL{
    public:
        long long n;
        
        string s;
        void takeDigit(ll x,vector<ll> &digits){
            if(x==0) digits.push_back(0);
            while(x){
                digits.push_back(x%10);
                x/=10;
            }
        }

        const long long maxsum = 181;
        bool kt(ll p){
            if(p<2) return false;
            for(int j=2;j<=sqrt(p);j++){
                if(p%j==0) return false;
            }
            return true;
        }

        long long dp[20][200][2];
        long long count(int idx, int sum, int tight, vector <ll> &digit){
            if(idx == -1){
                return kt(sum);
            }
            if(dp[idx][sum][tight]!=-1&&!tight) return dp[idx][sum][tight];
            ll k = (tight==1) ? digit[idx] : 9;
            ll res = 0   ;
            for(int i=0;i<=k;i++)
                res += count(idx-1, sum+i, (digit[idx]==i) ? tight : 0, digit);
    
            if(!tight)
                dp[idx][sum][tight]=res;
    
            return res;
            
        }

        void solve(){
            long long a, b;
            cin>>a>>b;
            memset(dp,-1,sizeof(dp));
            vector<ll> digitA,digitB;
            takeDigit(a-1,digitA);
            takeDigit(b,digitB);
            cout<<count(digitB.size()-1,0,1,digitB)- count(digitA.size()-1,0,1,digitA);
        }        
};
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();
}