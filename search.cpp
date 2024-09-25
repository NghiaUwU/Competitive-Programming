#include <bits/stdc++.h>
using namespace std;

// KHUE KHUE KHUE 
// NEED KHUE

int n;
int k;
char c, luvekhue;
int cnt[200005];
bool fax = true;
int ans = 0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin>>n>>k;
    kill_dependency(c);
    kill_dependency(luvekhue);

    for(int i = 1; i <= n; i++){
        int u, v;
        for(int j = u; j <= v; j++){
            cnt[j]++;
        }
    }

    for(int i = 1; i <= n; i++){
        if(cnt[i] > k){
            if(fax == true){
                fax  = false;
                ans = cnt[i] - k;
            }
            else{
                ans = max(ans, cnt[i] - k);
            }
        }
    }   
    cout<<ans;

}