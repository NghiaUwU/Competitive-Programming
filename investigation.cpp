#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

class Solution{
    public:
        ll dp[11][10002][90][2],a,b,k;
        void getDigit(ll x,vector<ll> &digits){
            if(x==0) digits.push_back(0);
            while(x){
                digits.push_back(x%10);
                x/=10;
            }
        }
        ll POW(ll m,ll p){
            ll aa = 1;
            while(p--){
                aa*=m;

            }
            return aa;
        }
        ll get(ll idx,ll sum,ll digit,ll tight,vector<ll> &digits){
            if(idx==-1){
                return (sum%k==0&&(digit%k)==0);
            }
            if(!tight&&dp[idx][sum][digit][tight]!=-1) return dp[idx][sum][digit][tight];
            ll bb=(tight==1) ? digits[idx] : 9;
            ll res=0;
            for(int i=0;i<=bb;i++)
                res+=get(idx-1,(sum+i*POW(10,idx))%k,(digit+i)%k,((i==digits[idx]) ? tight : 0),digits);
    
             if(!tight) dp[idx][sum][digit][tight]=res;
            return res;
        }
        void solve(){
            
            cin>>a>>b>>k;
            memset(dp,-1,sizeof(dp));
            vector<ll> digitA,digitB;
            getDigit(a-1,digitA);
            getDigit(b,digitB);
    
            cout<<get(digitB.size()-1,0,0,1,digitB)-get(digitA.size()-1,0,0,1,digitA);

        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution GHL;
    GHL.solve();
}