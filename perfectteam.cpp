#include <bits/stdc++.h>
using namespace std;
int k;
int cnt;
typedef long long ll;
void solve(){
    int m, x, c;
    cin>>c>>m>>x;
    x += abs(c - m);
        k = min(c, m);

        c = m = k;

        cnt = min(k, x);

        c -= cnt; m -= cnt;
        cnt += (c + m) / 3;

    cout<<cnt<<endl;

}
int main(){
    ios_base::sync_with_stdio(false);


    cin.tie(NULL);

    int test;
    cin>>test;
    while(test--){
        solve();
    }
}