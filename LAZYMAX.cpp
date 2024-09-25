#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;

const int N = 50000;
int maxValue[4 * N];
int delta[4 * N];

void update(int k, int l, int r, int x, int y, int d) {
    if (l > r || y < l || r < x)
        return;
    if (x <= l && r <= y) {
        maxValue[k] += d;
        delta[k] += d;
    } else {
        update(2 * k + 1, l, (l + r) / 2, x, y, d);
        update(2 * k + 2, (l + r) / 2 + 1, r, x, y, d);
        maxValue[k] = max(maxValue[2 * k + 1], maxValue[2 * k + 2]) + delta[k];
    }
}

int get(int k, int l, int r, int x, int y) {
    if (l > r || y < l || r < x)
        return INT_MIN;
    if (x <= l && r <= y)
        return maxValue[k];
    return max(get(2 * k + 1, l, (l + r) / 2, x, y), get(2 * k + 2, (l + r) / 2 + 1, r, x, y)) + delta[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int type, x, y;
        cin >> type >> x >> y;
        --x;
        --y;
        if (type == 0) {
            int delta;
            cin >> delta;
            update(0, 0, n - 1, x, y, delta);
        } else {
            printf("%d\n", get(0, 0, n - 1, x, y));
        }
    }
    return 0;
}

