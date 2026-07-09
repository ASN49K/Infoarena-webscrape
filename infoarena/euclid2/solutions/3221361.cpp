#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int v[100001];
int b[100001];
int cmmdc(int a,int b){
    if(a==0) return b;
    if(b==0) return a;
    while (b){
        int rest=a%b;
        a=b;
        b=rest;
    }
    return a;
}
int main() {
    int t,r;
    fin>>t;
    for(int i=1;i<=t;++i){
        fin>>v[i]>>b[i];
    }
    for(int i=1;i<=t;++i){
        r=cmmdc(v[i],b[i]);
        fout<<r<<"\n";
    }

    return 0;
}
