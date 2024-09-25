#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class SOL{
    public:
        int n, k;
        vector <pair <long long, long long> > atc;

        
        void solve(){
            cin>>n>>k;
            for(int i = 1; i <= n; i++){
                int u, v;
                cin>>u>>v;
                atc.push_back({u, v});
            }
            sort(atc.begin(), atc.end());
            for(int i = 0; i < n; i++) cout<<atc[i].first<<" "<<atc[i].second<<endl;

        }
};

SOL GHL;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    GHL.solve();
}

