#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class SOL{
    public:
        
};
long long n, q;
        long long a[500005];
        
        long long mx = 0;
        
        
 int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     cin>>n>>q;
            for(int i = 1; i <= q; i++){
                cin>>a[i];
                mx = max(mx, a[i]);
            }
            //cout<<"STABILIZE"<<'\n';
            ll ans = 0;
            int i;
            for(i = mx + 2;; i += 2 ){
                long long Pow = 1;
                
                if(ans > n){
                    cout<<"-1";
                    exit(0);
                }
                ans = 0;
                for(int j = 1; j <= q; j++){
                    ans += a[j] * Pow;
                    if(ans > n){
                        cout<<"-1";
                        exit(0);    
                    }
                    Pow *= i - 1;

                }
                if(ans == n){
                    cout<<i;
                    exit(0);
                }

                Pow = 1;
                
                ans = 0;
                for(int j = 1; j <= q; j++){
                    ans += a[j] * Pow;
                    if(ans > n){
                        cout<<"-1";
                        exit(0);    
                    }
                    Pow *= i;

                }
                if(ans == n){
                    cout<<i;
                    exit(0);
                }
                //cout<<i<<" "<<ans<<'\n';
            }

            cout<<i;
 }