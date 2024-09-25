#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


class SOL{
    public:
        
};
long long k;
        long long mod = 0;
        long long a[200005], x[200005];


        void solve(){
            
        }
 int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>k;
            for(int i = 1; i <= k; i++) cin>>a[i]>>x[i];
            long long mx = 1e18;
            long long dis = 0;
            long ans = 0;
            for(int i = 1; i <= k; i++){
                dis = 0;
                for(int j = 1; j <= k; j++){
                    dis += x[j] * abs(a[i] - a[j]);
                }
                if(mx >= dis){
                    ans = i;
                    mx = dis;
                }
            }

            cout<<ans;

 }
