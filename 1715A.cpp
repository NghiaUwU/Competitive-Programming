#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, m;
    cin>>n>>m;
    if(n == 1 && m == 1){
        cout<<"0"<<endl;
        return;
    }
    if(n < m)   swap(n, m);
    long long fir = m;
    long long sec = n + m - 2;
    cout<<fir + sec<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;
    while(test--)   solve();
}