#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll x, a[200005];
int marked[200005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>x;
    for(int i = 1; i <= n; i++) cin>>a[i];

    sort(a + 1, a + 1 + n);
    ll ans = 0;
    int l = 1, r = n;
    while(l < r){
        if(a[l] + a[r] > x){
            r--;
            
        }
        else{
            marked[l] = marked[r] = 1;
            l++;
            r--;
            ans++;
        }
    }    

    for(int i = 1; i <= n; i++) ans += (marked[i] == 0);
    cout<<ans;
}