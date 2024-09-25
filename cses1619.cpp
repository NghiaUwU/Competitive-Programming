#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

int n;
map <ll, int> timer;
long long storage[400005];
int k = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 1; i <= n; i++){
        ll x, y;
        cin>>x>>y;
        timer[x]++;
        timer[y]--;
        //fre[x]++;
        //fre[y]++;
        storage[++k] = x;
        storage[++k] = y;
    }
    ll ans = 0;
    ll mx = 0;
    sort(storage + 1, storage + 1 + k);
    for(int i = 1; i <= k; i++){
        //cout<<ans<<" "<<timer[storage[i]]<<' '<<storage[i]<<'\n';
        if(storage[i] != storage[i - 1]){
            ans += timer[storage[i]];
            mx = max(mx, ans); 
        }
        
    }
    cout<<mx;
}