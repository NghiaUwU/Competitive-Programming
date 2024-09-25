#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

void solve(){
    int max = 0;
    int point;
    int n, a[21];
    int check = 1;
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] > max){
            max = a[i];
            point = i;
        }
    }
    cout<<point<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* 
    YEU CHI KHUE NHAT
    YEU CHI KHUE NHAT
    YEU CHI KHUE NHAT
    */

   int test;

   cin>>test;
   while(test--)    solve();
}