#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve(){
    ll n, m;
    kill_dependency(n);
    kill_dependency(m);
    cin>>n>>m;
    if(n == 1 || m == 1){
        cout<<n<<" "<<m<<endl;
        return;
    }

    if(n == 2 && m == 2){
        cout<<n<<" "<<m<<endl;
        return;
    }
    if(n == 3 && n == 3){
        cout<<"2 2"<<endl;
        return;
    }
    if(n <= 2 && m <= 2){
        cout<<n<<" "<<m<<endl;
        return;
    }
    if(n == 2 && m == 3){
        cout<<"2 2"<<endl;
        return;
    }
    int midx = n / 2;
    int midy = m / 2;
    cout<<1<<" "<<m<<endl;
    return;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    kill_dependency(test);

    cin>>test;

    while(test--)   solve();
}