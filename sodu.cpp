#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class SOL{
    public:
        int n;
        int a[100005];

        void solve(){
            cin>>n;
            for(int i = 1; i <= n; i++) cin>>a[i];
            sort(a + 1, a + 1 + n);
            int ans = 0;
            for(int value = n; value >= n - 4; value--){
                for(int i = 1; i <= value; ++i){
                    ans = max(ans, a[value] % a[i]);
                }
            }

            cout<<ans;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();
}