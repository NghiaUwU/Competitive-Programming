#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



vector<ll> st_max, st_min, a;
 
void update_min(ll index, ll l, ll r, ll i, ll k)
{
    if (i < l || r < i)
        return;
    if (l == r)
    {
        st_min[index] = k;
        return;
    }
 
    ll mid = (l + r) / 2;
    update_min(index * 2, l, mid, i, k);
    update_min(index * 2 + 1, mid + 1, r, i, k);
    st_min[index] = min(st_min[index * 2], st_min[index * 2 + 1]);
}
 
ll get_min(ll index, ll l, ll r, ll u, ll v)
{
    if (v < l || r < u)
        return INT_MAX;
    if (u <= l && r <= v)
        return st_min[index];
 
    ll mid = (l + r) / 2;
    return min(get_min(index * 2, l, mid, u, v), get_min(index * 2 + 1, mid + 1, r, u, v));
}
void update_max(ll index, ll l, ll r, ll i, ll k)
{
    if (i < l || r < i)
        return;
    if (l == r)
    {
        st_max[index] = k;
        return;
    }
 
    ll mid = (l + r) / 2;
    update_max(index * 2, l, mid, i, k);
    update_max(index * 2 + 1, mid + 1, r, i, k);
    st_max[index] = max(st_max[index * 2], st_max[index * 2 + 1]);
}
 
ll get_max(ll index, ll l, ll r, ll u, ll v)
{
    if (v < l || r < u)
        return INT_MIN;
    if (u <= l && r <= v)
        return st_max[index];
 
    ll mid = (l + r) / 2;
    return max(get_max(index * 2, l, mid, u, v), get_max(index * 2 + 1, mid + 1, r, u, v));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     ll n, k;
    cin >> n >> k;
 
    st_min.assign(4 * n + 1, 1e10);
    st_max.assign(4 * n + 1, 1e10);
    a.assign(n + 1, 0);
 
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        update_max(1, 1, n, i, x);
        update_min(1, 1, n, i, x);
      
    }

    long long ans = 0;
    
    ll i = 1, j = 1, Max = a[1], Min = a[1], dis = 0;
    while(i <= j && j <= n){
        Max = get_max(1, 1, n, i, j);
        Min = get_min(1, 1, n, i, j);
        dis = Max - Min;
        if(dis <= k) {
            ans += (j - i + 1);
            j++;
        }
        else {
            i++;
        }
    }
    cout << ans;
    
}