#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[200005];
void solve(){
    int n, k;
    cin>>n>>k;
    memset(a, 0, n + 1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }  
    sort(a + 1, a + 1 + n);

    for(int i = 1; i < n; i++){
        if(abs(a[i] - a[i + 1]) % k == 0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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