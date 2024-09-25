#include <bits/stdc++.h>
using namespace std;

struct Matrix{
    long long matrx[3][3];
};

struct onetwo{
    long long u, v;
}; 
Matrix BASE;

Matrix multi(Matrix a, Matrix b){
    Matrix clone;
    clone.matrx[0][0] = a.matrx[0][0] * b.matrx[0][0] + a.matrx[0][1] * b.matrx[1][0];
    clone.matrx[0][1] = a.matrx[0][0] * b.matrx[0][1] + a.matrx[0][1] * b.matrx[1][1];
    clone.matrx[1][0] = a.matrx[1][0] * b.matrx[0][0] + a.matrx[1][1] * b.matrx[1][0];
    clone.matrx[1][1] = a.matrx[1][0] * b.matrx[0][1] + a.matrx[1][1] * b.matrx[1][1];
    return clone;
}

Matrix POW(Matrix a, long long n){
    Matrix res = a;
    Matrix use = BASE;

    while(n){
        if(n % 2)  use = multi(use, res);
        res = multi(res, res);
        n /= 2; 
    }
    return use;
}

onetwo moremul(onetwo example, Matrix x){
    onetwo res;
    res.u = example.u * x.matrx[0][0] + example.v * x.matrx[1][0];
    res.v = example.v * x.matrx[1][0] + example.v * x.matrx[1][1];
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, k;
    cin>>a>>b>>k;

    onetwo dat;
    dat.u = a;
    dat.v = b;

    Matrix M;
    M.matrx[0][0] = 0;
    M.matrx[0][1] = -1;
    M.matrx[1][0] = 1;
    M.matrx[1][1] = 2;

    BASE.matrx[0][0] = 1;
    BASE.matrx[1][1] = 1;
    BASE.matrx[0][1] = 0;
    BASE.matrx[1][0] = 0;

    Matrix ams = POW(M, k - 1);
    onetwo anss = moremul(dat, ams);

    cout<<anss.u<<'\n';
}