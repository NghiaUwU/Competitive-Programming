#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define Task "name"
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll N = 1e6 + 9;

ll ans = LLONG_MAX, a[N], n;
mt19937_64 rng(time(0));

void calc(ll p)
{
    ll sum = 0;
    for (int j = 1; j <= n; j++)
    {
        // sum=sum+min(a[j]%i,i-a[j]%i);
        if (a[j] < p)
            sum = sum + p - a[j];
        else
            sum = sum + min(a[j] % p, p - a[j] % p);
    }
    ans = min(ans, sum);
}
ll Rand(ll l, ll r)
{
    return uniform_int_distribution<ll>(l, r)(rng);
}
void timuoc(ll v)
{
    if (v < 2)
        return;
    for (int x = 2; x <= sqrt(v); x++)
    {
        if (v % x == 0)
            calc(x);
    }
}
void solve(ll t)
{
    timuoc(a[t]);
    timuoc(a[t] + 1);
    timuoc(a[t] - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    calc(2);
    for (int q = 1; q <= 10; q++)
    {
        solve(Rand(1, n));
    }
    cout << ans;
}