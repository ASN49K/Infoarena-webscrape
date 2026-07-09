#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],b[1025],m,n,nr,lcs[1025],k,c[1025][1025];
int backtrack(int i,int j)
{
    //fout<<a[i]<<" ";
    if(i==0||j==0) return 0;
    else if(a[i]==b[j]) {lcs[c[m][n]--]=a[i];backtrack(i-1,j-1)+a[i];}
    else if(c[i][j-1]>c[i-1][j]) backtrack(i,j-1);
    else backtrack(i-1,j);
}
int main()
{
    fin>>m>>n;
    for(int i=1; i<=m; i++) fin>>a[i];
    for(int i=1; i<=n; i++) fin>>b[i];

    for(int i=0;i<=m;i++) c[i][0]=0;for(int i=0;i<=n;i++) c[0][i]=0;
    for(int i=1;i<=m;i++)
        for(int j=0;j<=n;j++)
            if(a[i]==b[j])
                {c[i][j]=c[i-1][j-1]+1;
                 lcs[++nr]=a[i];}
            else c[i][j]= max(c[i-1][j],c[i][j-1]);

    nr=c[m][n];
    fout<<nr<<'\n';
    backtrack(m,n);
    //for(int i=1;i<=m;i++){for(int j=1;j<=n;j++) fout<<c[i][j]<<" ";fout<<'\n';}
    for(int i=1; i<=nr; i++) fout<<lcs[i]<<" ";

    return 0;
}
