#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

str s;
char c[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    int n;
    cin>>n;
    for(int i = 0; i < s.size(); i++)   c[i + 1] = s[i];
    for(int i = 1; i <= n; i++){
        int type;
        cin>>type;
        if(type == 1){
            int num;
            char x;
            cin>>num>>x;
            c[num] = x;

        }
        if(type == 2){
            int l, r;
            int cnt = 0;
            str t;
            cin>>l>>r>>t;
            int mod = t.size();
            int y = 0;
            for(int i = l; i <= r; i++){
                if(c[i] == t[y % mod])  cnt++;
                y++;
            }
            cout<<cnt<<endl;
        }
    }
}