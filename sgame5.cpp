#include <bits/stdc++.h>
using namespace std;
#define maximize(a, b) a = max(a, b)
#define minimize(a, b) a = min(a, b)

#define testBit(a, k) ((a >> k) & 1)
#define flipBit(a, k) (a ^ (1ll << k)
const int mxN = 20;
class Solution{
    public:
        
        int n;
        vector <double> f;
        vector<vector<double> > a;
        bool getBit(int mask, int bit) { return ((mask >> bit) & 1) == 1; }
        double recur(int row = 0, int mask = 0)
        {
            if (row == n) return 1;

             double &res = f[mask];
            if (res != -1) return res;
             res = 0;

            for (int col = 0; col < n; ++col)
             {   
                if (getBit(mask, col) == 0)
                {
                    int nmask = mask | (1 << col);
                double val = recur(row + 1, nmask);
                maximize(res, a[row][col] * val);
             }
            }

        return res;
}
        void solving(){
           
            cin>>n;

            
            a.assign(n, vector<double>(n, 0));

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    cin>>a[i][j];
                    a[i][j] /= 100;
                }
            }

            f.assign(1 << n, -1);

            

            cout<<fixed<<setprecision(9)<<recur() * 100;
            return;
            
        }
};

int main(){
    Solution khue;
    khue.solving();
}