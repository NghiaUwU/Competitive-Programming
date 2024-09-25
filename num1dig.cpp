#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;

class DP{
    public:
        ll n;
        int ans = 0;

        ll givenone(ll size){
            int cnt = 0;
            for(int i = 1; i <= size; i++){
                cnt *= 10;
                cnt++;
            }
            return cnt;
        }
        void solve(){
            cin>>n;
            string c = to_string(n);

            int sz = c.size();
            ans += 9 * (sz - 1);

            int chuot = givenone(sz);
            int temp = chuot;
            while(chuot <= n){
                ans++;
                chuot += temp;
            }
            cout<<ans;

        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    DP GHL;
    GHL.solve();
}