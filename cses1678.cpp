#include <bits/stdc++.h>


using namespace std;

#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int mxN = 1e5 + 1;

int n, m;
bool vis[mxN], in[mxN];
vector<int> adj[mxN], st;

void dfs(int u, int p) {
	vis[u] = in[u] = 1;
	st.push_back(u);
	for(int v : adj[u]) {
		if(v != p) {
			if(!vis[v])
				dfs(v, u);
			else if(in[v] == 1 && st.back() != v && st[st.size() - 2] != v) {
				vector<int> temp;
				temp.push_back(v);
				while(st.back() != v) {
					temp.push_back(st.back());
					st.pop_back();
				}
				temp.push_back(v);
				cout << temp.size() << "\n";
				for(auto i : temp)
					cout << i << " ";
				exit(0);
			}
		}
	}
	in[u] = 0;
	st.pop_back();
	return;
}

int main() {
	fastio;
	cin >> n >> m;

	while(m--) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}
	memset(vis, 0, sizeof(vis));
	memset(in, 0, sizeof(in));
	st.push_back(-1);
	for(int i = 1; i <= n; ++i)
		if(!vis[i])
			dfs(i, -1);
	cout << "IMPOSSIBLE\n";
	
	return 0;
}