#include <iostream>
#include <fstream>
#define nmax 1027
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,u,v[nmax],w[nmax],p[nmax][nmax],a[nmax],i,j,k,t;
int max(int a,int b){
return a>b?a:b;}
void citire(){
    fin>>m>>n;
    for(int i=1;i<=m;i++)
        fin>>v[i];
    for(int i=1;i<=n;i++)
        fin>>w[i];
}
int main()
{   citire();k=1;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(v[i]==w[j]){
                p[i][j]=p[i-1][j-1]+1;
            }
            if(v[i]!=w[j])
                p[i][j]=max(p[i-1][j],p[i][j-1]);
        }
    fout<<p[m][n]<<'\n';
    int h,g;
    h=m;
    g=n;
    for(k=1;k<=p[h][g];)
    {
        if(v[m]==w[n])
        {
            a[k]=v[m];
            m--;n--;k++;
        }
        else if(v[m]!=w[n])
        {
            t=max(p[m-1][n],p[m][n-1]);
            if(t==p[m-1][n])
                m--;
            else if(t==p[m][n-1])
                n--;
        }
    }
        for(i=p[h][g];i>=1;i--)
            fout<<a[i]<<" ";
    return 0;
}
