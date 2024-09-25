#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solving(){
    int n;
    memset(a, 0, n + 2);
    int l = 1, r = 1;
    bool fex = true;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] < a[i - 1])     fex = false;
    }
    if(fex == true){
        cout<<0<<endl;
        return;
    }
    for(int i = 1; i <= n - 1; i++){
        if(a[i + 1] < a[i]){
            
        }
    }
}
ll a[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    kill_dependency(test);
    cin>>test;

    while(test--)   solving();  

    
}