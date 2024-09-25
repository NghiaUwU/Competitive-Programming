#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 123456789;

ll a[100005], b[100005], k = 0;
int am, zero;
ll xet(ll x,ll y){
    if(x * y <0) return (((x * y) + MOD) %MOD)%MOD;
    return (x * y)%MOD;
}
void solve(){
    int n, m;
    am = 0;
    zero = 0;
    k = 0;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] < 0)    am++;
        if(a[i] == 0)   zero++;
    }

    long long tich = 1;
    if(am == 0){
        sort(a + 1, a + 1 + n, greater <long long> ());
        for(int i = 1; i <= m; i++){
            tich = ((tich % MOD) * (a[i] % MOD) % MOD) % MOD;
        }

        cout<<tich<<endl;
        return;
    }

    //cout<<am<<endl;
    
    sort(a + 1, a + 1 + n);
    
    int t = 1;
    int l = 1, r = n;
    if(k%2==1){
        if(a[n]<=0){
            for(ll j=n;j>=1&&k>0;j--,k--){
            t =(t * (a[j] + MOD) % MOD) %MOD;
             }
            cout << (t+MOD)%MOD << "\n";
            return;
         }
        k--;
        r--;
        t=xet(a[n],1);
    }
    while(k!=0){
        if(a[l] * a[l+1]<a[r] * a[r-1]){
        t=(t * xet(a[r],a[r-1]))%MOD;
        r-=2;
        
    }
        else{
             t=(t * xet(a[l],a[l+1]))%MOD;
            l+=2;
        }
        k-=2;
    }
        cout << t << "\n";
    
   

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("product.inp", "r")){
        freopen("product.inp", "r",stdin);
        freopen("product.out", "w", stdout);
    }
    int test;
    cin>>test;

    while(test--)   solve();
}