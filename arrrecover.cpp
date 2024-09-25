#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve(){
    int n;
    kill_dependency(n);
    cin>>n;

    vector <int> d(n + 2);
    vector <int> pro;
    for(int i = 1; i <= n; i++) cin>>d[i];
    int at = d[1];
    pro.push_back(at);
    for(int i = 2; i <= n; i++){
        if(d[i] == 0){
            pro.push_back(at);
        }
        if(d[i] < at){
            cout<<"-1"<<endl;
            return;
        }
        else{
            at = at + d[i];
            pro.push_back(at);
        }
    }

    for(int i = 0; i < pro.size(); i++) cout<<pro[i]<<" ";
    
}