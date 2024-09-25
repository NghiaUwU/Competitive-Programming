#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

class SOL{
    public:
        ll x, y, n, m;
        ll mol(ll a, ll b, ll mod){
            if (b == 0)
                return 0;
            ll t = 2 * mol(a, b / 2, mod) % mod;
            if (b % 2)
                return (a + t) % mod;
             return t;
        }
ll cal(ll a, ll n, ll m)
{
    ll res = a;
    ll ans = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
            ans = mol(res, ans, m);
        res = mol(res, res, m);
        n /= 2;
    }
    return ans;
}
        void solve(){
            cin >> x >> y >> n >> m;
            cout << (cal(x, n, m) - cal(y, n, m) + m) % m;
        }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();
}