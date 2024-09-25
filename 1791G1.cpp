#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class SOL{
    public:
        
};
ll n, c;
        ll a[200005];
        ll total[200005];

        void solve(){
            cin>>n>>c;
            for(int i = 1; i <= n; i++){
                cin>>a[i];
                total[i] = i + a[i];
            }
            sort(total + 1, total + 1 + n);
            int cnt = 0;
            for(int i = 1; i <= n; i++){
                if(c >= total[i]){
                    cnt++;
                    c -= total[i];
                }
                else    break;
            }
            cout<<cnt<<'\n';
        }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;
    while(test--){
        solve();

    }
}