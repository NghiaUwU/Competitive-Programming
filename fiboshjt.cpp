#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    int a[1000];
    a[1] = 1;
    a[2] = 1;
    for(int i = 1; i <= n; i++){
        if(i > 2)   a[i] = a[i - 1] + a[i - 2];
        cout<<a[i]<<" ";
    
    }
    cout<<'\n';
}