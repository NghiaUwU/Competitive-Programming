#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

long long s[102][102];
ll a[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,15, 16, 17};
void solve(){
    ll n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>s[i][j];
        }
    }
    
    
    long long ans = 0;
    long long temp = 0;
    for(int i = 1; i <= n; i++){
        temp += s[i][i];

    }
    ans = max(ans, temp);
    while(next_permutation(a + 1, a + 1 + n)){
        temp = 0;
        for(int i = 1; i <= n; i++){
            //cout<<i<<" "<<a[i]<<" "<<s[i][a[i]]<<endl;
            temp += s[i][a[i]];
        }
        //cout<<endl;
        ans = max(ans, temp);
    }

    cout<<ans<<endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;

    for(int x = 1; x <= test; x++){
        cout<<"Case "<<x<<": ";
        solve();
    }

}