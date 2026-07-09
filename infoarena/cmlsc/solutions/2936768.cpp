#include <bits/stdc++.h>


using namespace std;
const int N=1030;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[N],b[N],d[N][N];
void afiseaza(int lin,int col){

    if(d[lin][col]==0) return;
    if(a[lin]==b[col]) {
        afiseaza(lin-1,col-1);
        g<<a[lin]<<' ';
    }
    else {
        if(d[lin-1][col]>=d[lin][col-1])
            afiseaza(lin-1,col);
        else afiseaza(lin,col-1);
    }

}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++) f>>a[i];
    for(int i=1;i<=m;i++) f>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            d[i][j]=d[i-1][j-1]+1;
        else d[i][j]= max(d[i][j-1],d[i-1][j]);


    }
    g<<d[n][m]<<'\n';
    afiseaza(n,m);
    return 0;
}
