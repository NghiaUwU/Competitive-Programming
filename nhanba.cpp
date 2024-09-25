#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
const long long MOD = 123456789;

long long a[100001][10];
long long pown[100001][10];

void setup(){
    for(int i = 0; i <= 9; i++){
        a[0][i] = i;
        pown[0][i] = 10;
    }
     
    for(int i = 1; i <= 100000; i++){
        for(int d = 0; d <= 9; ++ d)
         {
            pown[i][d] = 1;
            int x = d * 3 / 10, y = d*3 % 10;
             if(x == 0) a[i][d] = a[i - 1][y];
             else   a[i][d] = (a[i - 1][x] * pown[i - 1][y] + a[i - 1][y]) % MOD;
          }
         for(int d = 0; d <= 9; ++ d)
        {
            pown[i][d] = 1;
            int x = d*3 / 10, y = d*3 % 10;
            if(x > 0) pown[i][d] = pown[i][d] * pown[i - 1][x] % MOD;
            pown[i][d] = pown[i][d] * pown[i - 1][y] % MOD;
         }
         
    }
 

}
void solve(){
    int m;
    string s;
    cin>>s>>m;

    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        int e = s[i] - 48;
        ans = (ans * pown[e][m] + a[e][m]) % MOD;
    }
    cout<<ans<<endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;
    setup();

    while(test--){
        solve();
    }

}