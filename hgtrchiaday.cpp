#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
long long a[200004], pre[200004]; 
int binary(int left, int right){
    if(right - left < 1)    return 0;
    
    int m = 0;
    int l = left;
    int r = right;

    while(l <= r){
        int mid = (l + r) / 2;
        long long leftsum = pre[mid] - pre[left - 1];
        long long rightsum = pre[right] - pre[mid];
       //cout<<mid<<' ';
        if(rightsum <= leftsum){
            if(leftsum == rightsum)
                m = mid;
            r = mid - 1;
        }
        else    l = mid + 1;
    }
    //cout<<'\n';
    return m;
}

int backspace(int l, int r, int cnt){
    int x = binary(l, r);
    
    if (x == 0)
        return cnt;
    else
        return max(backspace(l, x, cnt + 1), backspace(x + 1, r, cnt + 1));

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool iluvghl = true;

    int test;
    cin>>test;

    while(test--){
        
        cin>>n;

        memset(a, 0, sizeof(a));

        memset(pre, 0, sizeof(pre));

        for(int i = 1; i <= n; i++){
            cin>>a[i];
            pre[i] = pre[i - 1] + a[i];
        }

        cout<<backspace(1, n, 0)<<'\n';
    }

}