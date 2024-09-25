#include<bits/stdc++.h>
using namespace std;
vector<long long>A;
long long tsm(long long n)
{
    long long dem,tong=0;
    for(long long i=2;i<=sqrt(n);i++)
    {
        dem=0;
        while(n%i==0)
        {
            dem++;
            n=n/i;
        }
        tong=tong+dem;
    }
    if(n>1) tong++;
    return tong;
}
int main()
{
    long long i,n,t,ln=0,m=0,kq=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>t;
        A.push_back(t);
    }
    for(int i=0;i<=n-1;i++)
    {
        t=tsm(A[i]);
        kq=kq+t;
        m=max(m,t);
    }
    cout<<kq-m;
}