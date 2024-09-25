#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a, b, c, d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>a>>b>>c>>d;
    
    int cnt = 0;
    while(b > 0){
        cnt++;
        int usedngan = min(a - 1, c);
       
        c -= usedngan;
        usedngan++;
        int soluongbanh = min(usedngan * d, b);
        b -= soluongbanh;
        //cout<<soluongbanh<<" ";
    }
    cout<<cnt;



}