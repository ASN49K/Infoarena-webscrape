#include<bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int N,x,y;
int cmmdc(int a,int b){
    int r=a%b;
    while(r)a=b,b=r,r=a%b;
    return b;
}
int main()
{
    f>>N;
    while(N--){
        f>>x>>y;
        g<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
