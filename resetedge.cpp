#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    kill_dependency(n);
    kill_dependency(k);

    cin>>n>>k;
    vector <int> ast;
    ast.push_back(1);
    for(int i = 2; i <= n; i++){
        int pa;
        cin>>pa;
        ast.push_back(pa);
    }

    int cnt = 0;
    sort(ast.begin(), ast.end(), greater <int>());
    for(int i = 1; i <= k; i++){
        if(ast[cnt] == 1){
            cout<<"1"<<endl;
            return;
        }
        else    cnt++;
    }
    cout<<ast[cnt]<<endl;
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