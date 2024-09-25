#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const int N = 50000;
int maxValue[4 * N];
int delta[4 * N];

void update(int k, int l, int r, int x, int y, int d) {
    if (l > r || y < l || r < x)
        return;
    if (x <= l && r <= y) {
        maxValue[k] += d;
        delta[k] += d;
    } else {
        update(2 * k, l, (l + r) / 2, x, y, d);
        update(2 * k + 1, (l + r) / 2 + 1, r, x, y, d);
        maxValue[k] = max(maxValue[2 * k ], maxValue[2 * k + 1]) + delta[k];
    }
}
void input(int index, int l, int r, int i, int k){
	if(i < l || r < i)	return;
	if(l == r)	maxValue[l] = k;	return;
	int mid = (l + r) / 2;
	input(index * 2, l, mid, i, k);
	input(index * 2 + 1, mid + 1, r, i, k);
	maxValue[index] = max(maxValue[2 * index], maxValue[2 * index  + 1]);
	
}


int get(int k, int l, int r, int x, int y) {
    if (l > r || y < l || r < x)
        return INT_MIN;
    if (x <= l && r <= y)
        return maxValue[k];
    return max(get(2 * k, l, (l + r) / 2, x, y), get(2 * k + 1, (l + r) / 2 + 1, r, x, y)) + delta[k];
}

int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		int nu;
		cin>>nu;
		input(1, 1, n, i, nu);
	}
	while(m--){
		int type, x, y;
		cin>>type>>x>>y;
		if(type == 2){
			int d;
			cin>>d;
			update(1, 1, n, x, y, d);
		}
		else{
			cout<<get(1, 1, n, x, y)<<endl;
		}
	}
}
