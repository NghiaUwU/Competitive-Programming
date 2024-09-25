#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef uint64_t ull;
class Edge {
	public:
		int u, v;
		ull cost;
		inline bool operator>(const Edge& other) {
			return this->cost > other.cost;
		}
		inline bool operator<(const Edge& other) {
			return this->cost < other.cost;
		}
        
};
bool cmp(Edge x, Edge y) {
	return x.cost < y.cost;
}
const int mxN = 1e5 + 1;
 
int n, m, a, b, c, parent[mxN];
Edge Road[mxN << 1];
 
int find(int a){
    if(a != parent[a])  parent[a] = find(parent[a]);    //recursion find root
    return parent[a];
}

int united(int a, int b){
    int r1 = find(a);
    int r2 = find(b);

    if(r1 == r2)    return 0;
    return 1;
}

void unite(int A, int B) {
    int rootA = find(A);
    int rootB = find(B);
    parent[rootA] = rootB;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        cin>>Road[i].u>>Road[i].v>>Road[i].cost;
    }
    sort(Road, Road + m, cmp);
    for(int i = 1; i <= n; i++) parent[i] = i;

    ull res = 0LL;
    for(int i = 1; i <= m; i++){
        int find1 = find(Road[i].u);
        int find2 = find(Road[i].v);
        if (find1 == find2) continue;
		parent[find2] = find1;
		res += (ll) Road[i].cost;
    }
    cout<<res<<endl;
}