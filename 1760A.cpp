#include <bits/stdc++.h>
using namespace std;

class SOL{
    public:
        int a[5];
    vector <int> s;
    void solve(){
        cin>>a[1]>>a[2]>>a[3];
        sort(a + 1, a + 4);
        cout<<a[2]<<endl;
        s.clear();
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    SOL GHL;
    int test;
    cin>>test;
    for(int i = 1; i <= test; ++i)  GHL.solve();  
}