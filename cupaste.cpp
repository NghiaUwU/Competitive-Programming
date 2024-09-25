#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
    int state[1002][1002];
        int n, m;
        int cnt = 0;
        int highpoint = 0;
        int mark[1002][1002];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


       
            cin>>n>>m;
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= m; j++)
                    cin>>state[i][j];
            
            //cout<<"CODE CHAY DUOC"<<'\n';
            // LEFT
            highpoint = 0;
            for(int i = 1; i <= n; i++){
                highpoint = 0;
                for(int j = 1; j <= m; j++){
                    //cout<<highpoint<<" ";
                    if(state[i][j] > highpoint && state[i][j] != highpoint){
                        highpoint = state[i][j];
                        if(mark[i][j] == 0) cnt++;
                        mark[i][j] = 1;
                    }
                    
                }
                //cout<<cnt<<'\n';
            }

            // DOWN
            for(int j = 1; j <= m; ++j){
                highpoint = 0;
                for(int i = 1; i <= n; ++i){
                    //cout<<highpoint<<" ";
                    if(state[i][j] > highpoint && state[i][j] != highpoint){   
                        highpoint = state[i][j];
                        if(mark[i][j] == 0) cnt++;
                        mark[i][j] = 1;
                    }
                }
                //cout<<cnt<<'\n';
            }

            // RIGHT
            for(int i = n; i >= 1; i--){
                highpoint = 0;
                for(int j = m; j  >= 1; j--){
                    //cout<<highpoint<<" ";
                    if(state[i][j] > highpoint && state[i][j] != highpoint){   
                        highpoint = state[i][j];
                        if(mark[i][j] == 0) cnt++;
                        mark[i][j] = 1;
                    }
                }
            }

            // UP
            for(int j = m; j >= 1; j--){
                highpoint = 0;
                for(int i = n; i >= 1; i--){
                    if(state[i][j] > highpoint && state[i][j] != highpoint){   
                        highpoint = state[i][j];
                        if(mark[i][j] == 0) cnt++;
                        mark[i][j] = 1;
                    }
                }
            }
            cout<<cnt<<'\n';
            
        
}