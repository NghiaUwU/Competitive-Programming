#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

class SOL{
    public:
        
};
int n, m;
        ll k, a[200005], b[200005];

        void solve(){
            cin>>n>>m>>k;
            for(int i = 1; i <= n; i++) cin>>a[i];
            for(int i = 1; i <= m; i++) cin>>b[i];

            sort(a + 1, a + 1 + n);
            sort(b + 1, b + 1 + m);
            /*
            for(int i = 1; i <= n; i++) cout<<a[i]<<' ';
            cout<<'\n';
            for(int i = 1; i <= m; i++) cout<<b[i]<<' ';
            cout<<'\n';
            */
            int pointer1 = 1, pointertwo = 1;
            int ans = 0;
            while(pointertwo <= m){
                if(b[pointertwo] >= a[pointer1] - k && b[pointertwo] <= a[pointer1] + k){
                    ans++;
                    pointer1++;
                    pointertwo++;
                }
                if(b[pointertwo] < a[pointer1] - k)  pointertwo++;
                if(b[pointertwo] > a[pointer1] + k) pointer1++;
            }

            cout<<ans;
        }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}