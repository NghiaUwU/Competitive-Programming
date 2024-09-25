#include <bits/stdc++.h>
using namespace std;

int n;
deque <int> khue;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = n; i >= 1; i--){
        if(i % 2 == 0)  khue.push_back(i);
        else    khue.push_front(i);
    }
    for(int i = 0; i < khue.size(); i++)    cout<<khue[i]<<" ";
}