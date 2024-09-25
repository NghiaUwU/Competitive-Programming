#include <bits/stdc++.h>

#define int long long
typedef string str;

using namespace std;

int ST[400005], n;
int a[100005], b[100005];
void update(int id, int l, int r, int i) {
    if (i < l || r < i) {
        return ;
    } if (l == r) {
        ST[id]++;
        return ;
    }

    int mid = (l + r) / 2;
    update(id*2, l, mid, i);
    update(id*2 + 1, mid+1, r, i);

    ST[id] = ST[id*2] + ST[id*2+1];
}
int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return 0;
    } if (u <= l && r <= v) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    return (get(id*2, l, mid, u, v) + get(id*2 + 1, mid+1, r, u, v));
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {cin >> a[i]; b[i] = a[i];}
    sort(b + 1, b + 1 + n);
    for(int i = 1; i <= n; ++i){
        int p = upper_bound(b + 1, b + 1 + n, a[i]) - b - 1;
        update(1, 1, n, p);
        cout << get(1, 1, n, p + 1, n) + 1 << '\n';
    }
}
