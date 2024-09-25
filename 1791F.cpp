#include <bits/stdc++.h>
using namespace std;

class SOL{
    public:
        
};
typedef long long ll;

int n, q;
long long a[200005];
long long cnt[200005];
long long at[200005];
long long matrix[200005][4];
long long mx[200005];

int sum(long long x){
    int tong = 0;
    while(x != 0){
        tong += x % 10;
        x /= 10;
    }
    return tong;
}

void solve(){
    cin>>n>>q;
        
            for(int i = 1; i <= n; i++){
                cin>>a[i];
            }
            for(int i = 1; i <= n; i++){
                int cnt = 0;
                matrix[i][cnt] = a[i];
                while(a[i] > 10){
                    int tong = 0;
                    long long cop = a[i];
                    while(cop != 0){
                        tong += cop % 10;
                        cop /= 10;
                    }
                    matrix[i][cnt + 1] = tong;
                    cnt++;
                    a[i] = tong;
                }
                mx[i] = matrix[i][cnt];
            }

            bool w = false;
            bool pass = false;
            while(q--){
                int kind, x, b;
                cin>>kind;
                if(kind == 1){
                    cin>>x>>b;
                    cnt[x]++;
                    if(b + 1 < n) cnt[b + 1]--;      
                    w = true;
                    pass = true;
                }
                else if(kind == 2){
                    cin>>x;
                    if(pass == false){
                        pass = true;
                        cout<<matrix[x][0]<<'\n';
                        continue;
                    }
                    if(w == true){
                        for(int i = 1; i <= n; i++){
                            cnt[i] += cnt[i - 1];
                            at[i] += cnt[i];
                            //cout<<cnt[i]<<" "<<at[i]<<'\n';
                            cnt[i - 1] = 0;
                        }
                       // cout<<'\n';
                        w = false;
                    }
                    
                    long long ans;
                    //cout<<at[x]<<' ';
                    if(matrix[x][at[x]] == 0)  ans = mx[x];
                    else    ans = matrix[x][at[x]];
                    cout<<ans<<'\n';
                }
            }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test;
    cin>>test;
    while(test--){
        solve();
    }
}