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

    int p;
    cin>>p;
    for(int i = 1; i <= mxN; ++i)
		parent[i] = i;
    while(p--){
        cin>>a>>b>>c;
        if(c == 1){
            unite(a, b);
        }
        if(c == 2){
            if(united(a, b) == 0)    cout<<"1"<<endl;
            else    cout<<"0"<<endl;
        }
    }
}