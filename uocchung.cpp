#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

vector <long long> a;
vector <long long> seg;
void update(int index, int l , int r, int i, int k){
    if(i <  l || r < i) return;
    if(l == r){
        seg[index] = k;
        return;
    }
    ll mid = (l + r) / 2;
    update(index * 2, l, mid, i, k);
    update(index * 2 + 1, mid + 1, r, i, k);
    seg[index] = __gcd(seg[2 * index], seg[2 * index + 1]);

}


ll gcd(ll index, ll l, ll r, ll u, ll v)
{
    if (v < l || r < u)
        return 0;
    if (u <= l && r <= v)
        return seg[index];

    ll mid = (l + r) / 2;
    return __gcd( gcd(index * 2, l, mid, u, v) , gcd(index * 2 + 1, mid + 1, r, u, v)) ;
}
void solve(){
    int n;
    cin>>n;
    a.assign(n + 1, 0);
    seg.assign(4 * n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        update(1, 1, n, i, abs(a[i]));
    }

    int l = 1, r = 1;
    int range = 0;

    while(l <= n && r <= n){
        if(gcd(1, 1, n, l, r) != 1){
            range = max(range, r - l + 1);
            r++;
        }
        else{
            range = max(range, r - l);
            l++; 
        }
       
        
    }


    cout<<range<<endl; 
    kill_dependency(range);
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