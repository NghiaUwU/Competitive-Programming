#include<bits/stdc++.h>
using namespace std;
long long f[9];
vector<int> q[9];
typedef string str;

const long long MAX = 1e9;
void sas()
{
    for(int i = 0; i < 9; i++){
        f[9] = 0;
        while(q[i].size() > 0) q[i].pop_back();
    }
}

void solvingforques(){
    str s;
        int n, m;

        cin>>s>>n>>m;


        vector<int> du, cd;

        cd.push_back(0);
        sas();
        for(int j = 1; j <= s.size(); j++) cd.push_back((cd[j-1] + s[j-1] - 48 ) %9);

        for(int x = 0; x < 9; x++) f[x] = 0;
        int tong = 0;

        for(int j = 0; j < n; j++) tong = (tong + s[j] - 48) % 9;
        for(int j = n; j <= s.size(); j++){
            if(f[tong] <= 1) q[tong].push_back(j- n +1);
            f[tong]++;
            du.push_back(tong);
            if(j < s.size()) tong = (tong + s[j] - s[j -n] + 90 ) %9;
        }

        //section 2

        for(int j = 0; j < m; j++){
            int l, r, ki;
            cin>>l>>r>>ki;
            int doan = (cd[r] - cd[l-1] + 9)%9;
            int minimum1 = 1e9, minimum2 = 1e9;
            for(int k = 0; k < 9; k++) if(f[k] > 0){
                int l1 = q[k][0], ano = ((ki + 90) - (k*doan))%9;
                int l2;
                if(ano == k){
                    if(f[ano] <= 1) continue;
                    else l2 = q[k][1];
                }
                else{
                    if(f[ano] == 0) continue;
                    else l2 = q[ano][0];
                }
                if(l1 < minimum1 || (l1 == minimum1 && l2 < minimum2)) {minimum1 = l1; minimum2 = l2;}
            }

            if(minimum1 == MAX) cout<<"-1 -1"<<endl;
            else cout<<minimum1<<" "<<minimum2<<endl;
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    while(t--){
        solvingforques();
    }
}