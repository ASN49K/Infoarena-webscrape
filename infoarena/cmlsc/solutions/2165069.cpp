#include<bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int N,M,a[1025],b[1025],D[1025][1025],rez[1025],l;
int main()
{
    f>>M>>N;
    for(int i=1;i<=M;++i)f>>a[i];
    for(int j=1;j<=N;++j)f>>b[j];
    for(int i=1;i<=M;++i)
        for(int j=1;j<=N;++j)
            if(a[i]==b[j])D[i][j]=D[i-1][j-1]+1;
            else D[i][j]=max(D[i-1][j],D[i][j-1]);
    int i=M,j=N;
    while(i)
        if(a[i]==b[j])rez[++l]=a[i],--i,--j;
        else if(D[i-1][j]<D[i][j-1])--j;
        else --i;
    g<<l<<'\n';
    while(l)g<<rez[l--]<<' ';
    return 0;
}
