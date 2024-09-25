#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll a[200005];
ll b[200005];
  
int replace(ll n){
    int cnt = 0;
    while(n != 0){
        cnt++;
        n /= 10;
    }
    return cnt;
}
void solve(){
    
    cin>>n;
    map <ll, int> cnt;  
    for(int i = 1; i <= n; i++){

        cin>>a[i];
        cnt[a[i]]++;
      
    }
    for(int i = 1; i <= n; i++){
        cin>>b[i];
        cnt[b[i]]++;
      
    }
    // KIEM TRA 1

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        while(cnt[a[i]] % 2 != 0 && a[i] != 1){
            cnt[a[i]]--;
            cnt[replace(a[i])]++;
            a[i] = replace(a[i]);
            ans++;

        }
        while(cnt[b[i]] % 2 != 0 && b[i] != 1){
            cnt[b[i]]--;
            cnt[replace(b[i])]++;
            b[i] = replace(b[i]);
            ans++;
        }
    }
    cout<<ans;
    cout<<endl;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    
    int test;

   cin>>test;
   while(test--)    solve();
}