#include <bits/stdc++.h>
using namespace std;

typedef uint64_t ll;
struct SEG{
    int a, b;
    ll cost;
    inline bool operator>(const SEG& other) {
		return this->cost > other.cost;
	}
	inline bool operator<(const SEG& other) {
		return this->cost < other.cost;
	}
};

SEG path[100005 + 1];
int parent[400005 + 2210];

int find(int a){
    if(a != parent[a])  parent[a] = find(parent[a]);    //recursion find root
    return parent[a];
}

inline bool unite(int a, int b){
    int r1 = find(a);
    int r2 = find(b);

    if(r1 == r2)    return 0;
    parent[r2] = r1;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        unsigned long long x, y, z;
        cin>>x>>y>>z;
        path[i].a = x;
        path[i].b = y;
        path[i].cost = z;
    }

    sort(path, path + m);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    ll ans = 0;
    int road = n - 1;

    for(int i = 0; road && i < m; i++){
        if(unite(path[i].a, path[i].b)){
            ans += path[i].cost;
            road--;
        }
    }
    if(!road)   cout<<ans;
    else    cout<<"IMPOSSIBLE";
}