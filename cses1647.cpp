#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long mx = 89017893764523;
class GHL{
    public:
        long long n;
        vector <long long> a, tree;
        void update(int index, int l, int r, int k, int i){
            if(l > i || r < i)  return;
            if(l == r){
                tree[index] = k;
                return;
            }

            int mid = (l + r) / 2;
            update(index * 2, l, mid, k, i);
            update(index * 2  + 1, mid + 1, r, k, i);

            tree[index] = min(tree[index * 2], tree[index * 2 + 1]);

        }       
        long long damin(int index, int l, int r, int u, int v){
            if(l > v || r < u)  return mx;
            if(u <= l && r <= v)    return tree[index];

            int mid = (l + r) / 2;
            return min(damin(index * 2, l, mid, u, v), damin(index * 2 + 1, mid + 1, r, u, v));
        }

        void solving(){
            cin>>n;
            int q;
            cin>>q;
            a.resize(n + 1);
            tree.resize(4 * n + 4);

            for(int i = 1; i <= n; i++){
                cin>>a[i];
                update(1, 1, n, a[i], i);
            }
            for(int i = 1; i <= q; i++){
                int u, v;
                cin>>u>>v;
                cout<<damin(1, 1, n, u, v)<<endl;
            }

        }

    private:
        string sirrabbit = "SIR";
};
GHL rabiit;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    rabiit.solving();
}