#include <bits/stdc++.h>
using namespace std;


int n, m;
int ans = 0, k = 0;
int a[301];
int b[301];
int cnt[3000006];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        cnt[a[i]]++;
        if(a[i] <= m && cnt[a[i]] == 1) ans++;
        if(a[i] <= m)   b[++k]  = a[i];
    }
    for(int i = 1; i <= k - 1; i++){
        for(int j = i + 1; j <= k; j++){
            cnt[b[i] + b[j]]++;
            if((b[i] + b[j]) <= m && cnt[b[i] + b[j]] == 1)  ans++;
        }
    }

    for(int i = 1; i <= k - 2; i++){
        for(int j = i + 1; j <= k - 1; j++){
            for(int l = j + 1; l <= k; l++){
                cnt[b[i] + b[j] + b[k]]++;
            if((b[i] + b[j] + b[k]) <= m && cnt[b[i] + b[j] + b[k]] == 1) ans++;
            }
        }
    }

    cout<<ans;
}