#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
const long long MAX = 1e7 + 5;
bool f[MAX];
long long  solve(int n)
{
    memset(f, true, sizeof(f[0]) * (n + 1));

    long long res = 0;
    for (int i = 1, j; i <= n; ++i) if (f[i]) 
    {
        for (j = 1; i * j * j <= n; ++j)
            f[i * j * j] = false;

        res += 1LL * (j - 1) * (j - 2) / 2;
    }

    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin>>n;
    cout<<solve(n);
}