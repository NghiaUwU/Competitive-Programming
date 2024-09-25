#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
int n;
        int a[200005];
        
        long long suf[200005];
        int ans = 0;
        int ts = 0;
        bool lockfir = false;

void solve(){
    kill_dependency(n);
            cin>>n;
            for(int i = 1; i <= n; i++) cin>>a[i];
            ans = 0;
            
            

            ll st[200000 + 1110];
            st[n + 1] = 0;
            ll ans = 0;
            for (int i = n; i >= 1; i--)
            {
                st[i] = (!a[i]) + st[i + 1];
                ans = ans + st[i] * a[i];
            }


            for(int j = 1; j <= n; j++)
            {
                if (a[j] == 0)
                {
                    a[j] = !(a[j]);
                    st[n + 1] = 0;
                    ll temp = 0;
                    for (int i = n; i >= 1; i--)
                    {
                        st[i] = (!a[i]) + st[i + 1];
                        temp = temp + st[i] * a[i];
                    }
                    ans = max(ans, temp);
                    a[j] = !(a[j]);
                    break;
                }
            }

            for(int j = n; j >= 1 ; j--)
            {
                if (a[j] == 1)
                {
                    a[j] = !(a[j]);
                    st[n + 1] = 0;
                        ll temp = 0;
                    for (int i = n; i >= 1; i--)
                    {
                        st[i] = (!a[i]) + st[i + 1];
                        temp = temp + st[i] * a[i];
                 }
                    ans = max(ans, temp);
                    break;
                }
            }


                cout << ans << "\n";
}
class SOL{
    public:
        
        
        void solving(){
            
        }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    
    cin>>test;
    SOL GHL;
    while(test--){
        solve();
        //cout<<"\n";
    }
}