#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

class SOL{
    public:
        void takeDig(string &n, vector <long long> &dig){
            if(n == "0")  dig.push_back(0);
            for(int i = n.size() - 1; i >= 0; --i)  dig.push_back((int) n[i] - 48);
        }

        long long query(long long idx )
};