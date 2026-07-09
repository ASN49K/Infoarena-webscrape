#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1025],b[1025],c[1024][1024],k;
int sir[1025];
void Read()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    fin.close();
}

void afisare()
{  int i,j;
    for( i=n,j=m;i>=1;)
        if(a[i]==b[j])
    {
        sir[++k]=a[i]; i--; j--;
    }
    else
        if(c[i-1][j]<c[i][j-1]) j--;
        else i--;

    fout<<k<<"\n";
    for(i=k;i>=1;i--)
        fout<<sir[i]<<" ";
}
void Solve()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(a[i]==b[j]) c[i][j]=1+c[i-1][j-1];
         else c[i][j]=max(c[i-1][j], c[i][j-1]);

     afisare();

}
int main()
{
     Read();
     Solve();

    return 0;
}
