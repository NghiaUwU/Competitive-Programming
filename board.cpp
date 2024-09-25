#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SOL{
    public:
        int n, m;
        int matrix[103][103];
        int marked[103][103];

        long long dif = 0;
        long long ans = 0;
        long long res = 0;
        
        void dfs(long long x, long long y, long long &ans){
            //cout<<"I WORKED"<<'\n';
            //if(x > n || y > m)  return;
            //cout<<x<<" "<<y<<" "<<ans<<'\n';
            marked[x][y] = 1;
            for(int i = 0 ; i <= 2 ; i++){
                for(int j = 0 ; j <= 2; j++){
                    //cout<<x + i - 1<<' '<<y + j - 1<<'\n';
                    if(matrix[x + i - 1][y + j - 1] == matrix[x][y] && marked[x + i - 1][y + j - 1] == 0){
                        ans++;
                        dfs(x + i - 1, y + j - 1, ans);
                    }
                }
            }
        }
        void solve(){
            int n, m;
            cin>>n>>m;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    cin>>matrix[i][j];
                    marked[i][j] = 0;
                }
            }
            dif = 0;
            for(int a = 1; a <= n; a++){
                for(int b = 1; b <= m; b++){
                    if(marked[a][b] == 0){
                        dif++;
                        //cout<<' '<<a<<' '<<b<<' '<<dif<<'\n'<<"LIS: ";
                        ans = 1;
                        dfs(a, b, ans);
                        if(ans == 1)    dif--;
                        res = max(res, ans);
                        //cout<<"ANS: "<<ans<<" ";
                        //cout<<"END"<<'\n';
                    }
                }
            }

            cout<<dif<<'\n'<<res;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("CAU4.inp", "r", stdin);
    freopen("CAU4.out", "w", stdout);
    SOL GHL;
    GHL.solve();
}