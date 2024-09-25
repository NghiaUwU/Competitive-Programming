#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
map <int, int> cnt;
int k = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 1; i <= n; i++){
        ll x;
        cin>>x;
        cnt[x]++;
        if(cnt[x] == 1) k++;
    }

    cout<<k;

}