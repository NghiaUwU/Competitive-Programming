#include <iostream>
#include <cstdio>
using namespace std;

#define ll long long

const int INF = 300009;

struct node {
    ll key;
    int pos;
} dtmin[INF], dtmax[INF];
ll n, d, t, x, M;
ll pre[INF];
int f[INF], ans[INF], namax[INF], namin[INF];

inline int Searchmax (int x, ll k) {
    while (dtmax[x].key - k >= d) {
        if (x > M) return dtmax[x].pos;
        if (dtmax[x << 1 | 1].key - k >= d) x = x << 1 | 1;
        else
            x = x << 1;
    }
    return 0;
}
inline int Searchmin (int x, ll k) {
    while (k - dtmin[x].key >= d) {
        if (x > M) return dtmin[x].pos;
        if (k - dtmin[x << 1 | 1].key >= d) x = x << 1 | 1;
        else
            x = x << 1;
    }
    return 0;
}

inline void modify (int x, ll k, int i) {
    if (dtmax[x + M].key < k) namax[x] = i, dtmax[x + M].key = k;
    for (int t = x + M; dtmax[t >> 1].key < k && t > 0; t >>= 1)
        dtmax[t >> 1] = dtmax[t];

    if (dtmin[x + M].key > k) namin[x] = i, dtmin[x + M].key = k;
    for (int t = x + M; dtmin[t >> 1].key > k && t > 0; t >>= 1)
        dtmin[t >> 1]  = dtmin[t];
}

int main() {
    ios::sync_with_stdio (false);
    cin >> n >> d;
    cin>>x;
    M = n;
    int tem = 0;
    for (int k = M; k; tem++, k >>= 1) ;
    M = 1 << tem;
    for (int i = 0; i < (M << 1) + 10; i++) {
        dtmax[i].key = 0 , dtmin[i].key = (1LL << 60);
        dtmax[i].pos = i - M, dtmin[i].pos = i - M;
    }
    dtmax[1].key = dtmin[1].key = x;
    t = f[1] = 1;
    modify (t, x, 1);
    for (int i = 2,k; i <= n; i++) {
        cin >> x;
        if (k = Searchmax (1, x) )
            if (f[i] < k + 1)
                f[i] = k  + 1, pre[i] = namax[k];

        if ((k = Searchmin (1, x)))
            if (f[i] < k + 1)
                f[i] = k  + 1, pre[i] = namin[k];

        if (f[i] > t) t = f[i];
        if (f[i] == 0)   f[i] = 1;
        modify (f[i], x, i);
    }
    cout << t << endl;
    int p = -1;
    for (int i = 1; i <= n; i++)  if (f[i] == t) { p = i; break; }
    for (int i = t; i; i--)
        ans[i] = p, p = pre[p];
    for (int i = 1; i <= t; i++)
        cout << ans[i] << ' ';
}
