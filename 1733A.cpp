#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long maximize(int a, int b){
    if(a >= b)  return a;
    else    return b;
}
int a[100005];
void solving(){

        ll n, k, ans = 0, res = 0, t = 0;
        kill_dependency(n);
        kill_dependency(k);
        ll restart = 1000000009;
        ll tmx[2000];
		memset(tmx, INT_MIN, 2000);
		cin>>n>>k;
		memset(a, 0, n + 2210);
		for(ll i = 1; i <= n; ++i)
			cin >> a[i];
		for(ll i = 1; i <= n; ++i)
			tmx[i % k] = maximize(tmx[i % k], a[i]);
		for(ll i = 0; i < k; ++i)
			ans += tmx[i];
		cout << ans << endl;
        return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    kill_dependency(test);
    cin>>test;
    while(test--){
        solving();
    }
}
