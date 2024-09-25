#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("BAI1.INP", "r")){
        freopen("BAI1.INP", "r", stdin);
        freopen("BAI1.OUT", "w", stdout);
    }
    int g, h, l;
    cin>>g>>h>>l;

    int dis = abs(h - l);
    int ans = g / dis;
    if(g % dis != 0)    ans++;
    cout<<ans;
}