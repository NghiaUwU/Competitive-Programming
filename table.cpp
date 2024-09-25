#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

int n, k;
long long a[1003][10004];

long long d, r, q;
long long type, u, v, x, y;
long long lazyd = 0, lazyr = 0;
long long changex, changey;
void solve(){
    cin>>n>>k;
           
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin>>a[i][j];
            a[i + n][j] = a[i][j];
            a[i][j + k] =  a[i][j];
            a[i + n][j + k] = a[i][j];
        }
            
    }
    cin>>q;
    while(q--){
        cin>>type;
        if(type == 1){
            cin>>u>>v;
            lazyd += u, lazyr += v;
        }
        else{
            cin>>u>>v>>x>>y;  
            // (u, v) : goc trai
            // (x ,y) : goc phai

            int posu = (u + lazyd - 1) % (n);
            int posv = (v + lazyr - 1) % (k);

            int posx = (x + lazyd - 1 + n) % n;
            int posy = (y + lazyr - 1 + k) % k;

            if(posx < posu) posx += n;
            if(posy < posv) posy += k;
            
            //cout<<posu<<" "<<posv<<" "<<posx<<" "<<posy<<'\n';
            long long ans = -1e18;
            for(int i = posu; i <= posx; ++i)
                for(int j = posv; j <= posy; ++j)
                    ans = max(ans, a[i][j]);

            cout<<ans<<'\n';
        }
    }
}    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}