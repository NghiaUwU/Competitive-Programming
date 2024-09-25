#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

int n, m;

vector <int> dsu;

// STRUCT DSU
int get (int x) { return (dsu[x] < 0 ? x : dsu[x] = get(dsu[x])); }
void fex(int n){dsu.assign(n + 1, -1);}
int sia (int x) {return -dsu[get(x)];}


	bool unite (int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return 0;
		if (dsu[x] > dsu[y]) swap(x, y);
		dsu[x] += dsu[y];
		dsu[y] = x;
		return 1;
	}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    fex(n);

    int siz = 1, num = n;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin>>x>>y;
        x--; y--;
		if (unite(x, y)) {
			siz = max(siz, sia(x));
			num--;
		}
		cout<<num<<" "<<siz<<endl;        
    }
}