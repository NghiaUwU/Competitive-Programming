#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

class SOL{
    public:
        

        void solve(){
            
        }
};
long long n, q;
        long long a[1000006];
        map <long long, long long> cnt;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;
            for(int i = 1; i <= n; i++){
                cin>>a[i];
                cnt[a[i]]++;
            }
            while(q--){
                long long x; 
                cin>>x;

                if(cnt[x] == 0){
                    cout<<"-1"<<'\n';
                    continue;
                }
                int l = 1, r = n, mid;
                while(l <= r){
                     mid = (l + r) / 2;
                    if(a[mid] <= x) l = mid + 1;
                    else    r = mid - 1;
                }
                cout<<mid<<'\n';
                //nex:
            }
}

