#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");ofstream fout("cmlsc.out");
int i,j,m,n;
int a[100001],b[100001];
int t[10001][10001],ras[100001];
int maxim(int a,int b)
{
    return a > b ? a : b;
}
void lcs(int a[],int b[],int n,int m)
{
    int length=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if (a[i]==b[j])t[i][j]=1+t[i-1][j-1];
                else t[i][j]=maxim(t[i-1][j],t[i][j-1]);
    for (i=n,j=m;i;)
        if(a[i]==b[j])
        {
            ras[++length]=a[i];
            i--;
            j--;
        }
        else if (t[i-1][j]<t[i][j-1]) j--;
            else i--;
    fout<<length<<'\n';
    for (i = length; i; --i) fout<<ras[i]<<' ';
}
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(j=1;j<=m;j++)
        fin>>b[j];
    lcs(a,b,n,m);
}
