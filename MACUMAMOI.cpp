#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
ll M=1e9;

struct sus{
	ll hi, power;
};
vector<sus> st;
ll read(){}
void update(ll index, ll l, ll r, ll i, ll k)
{
    if (i < l || r < i)
        return;
    if (l == r)
    {
    	st[index].hi++;
        st[index].power += k;
        return;
    }

    ll mid = (l + r) / 2;
    update(index * 2, l, mid, i, k);
    update(index * 2 + 1, mid + 1, r, i, k);
    st[index].hi = st[index * 2].hi + st[index * 2 + 1].hi;
    st[index].power = st[index * 2].power + st[index * 2 + 1].power;
}
int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return 0;
    } if (u <= l && r <= v) {
        return st[id].power;
    }
    int mid = (l + r) / 2;
    return (get(id*2, l, mid, u, v) + get(id*2 + 1, mid+1, r, u, v));
}
ll tmx(ll index, ll l, ll r, ll u, ll v)
{
    if (v < l || r < u)
        return 0;
    if (u <= l && r <= v)
        return st[index].hi;

    ll mid = (l + r) / 2;
    return tmx(index * 2, l, mid, u, v) +tmx(index * 2 + 1, mid + 1, r, u, v);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, sum =0;
    cin >> n;
    int a[n + 2], b[n + 2];
    st.resize(4 * n  + 6);
    for(int i = 1; i <= n; ++i) {cin >> a[i]; b[i] = a[i];}
    sort(b + 1, b + 1 + n);
    for(int i = 1; i <= n; ++i){
        int p = upper_bound(b + 1, b + 1 + n, a[i]) - b - 1;
        update(1, 1, n, p, a[i]);
        int x = get(1, 1, n, p + 1, n);
        int y = tmx(1, 1, n, p + 1, n);
        int res = (x - y * a[i]) % M;
        sum = (sum + res) % M;
    }
    cout<<sum;
}
