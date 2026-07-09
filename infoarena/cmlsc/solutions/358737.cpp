#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025],b[1025],l[1025][1025],m,n,sol[1024],nrsol;

int main()
{
    fin>>m>>n;
    int i,j;
    for (i=1;i<=m;i++)
        fin>>a[i];
    for (i=1;i<=n;i++)
        fin>>b[i];
    fin.close();
    for (i=0;i<=m;i++)
     for(j=0;j<=n;j++)
         if(i==0||j==0) l[i][j]=0;
         else  if(a[i]==b[j]) l[i][j]=1+l[i-1][j-1];
                else l[i][j]=l[i-1][j]>l[i][j-1]?l[i-1][j]:l[i][j-1];
    /*cout<<"  ";
    for(i=0;i<=n;i++)
     cout<<b[i]<<" ";
    cout<<'\n';
    for (i=0;i<=m;i++)
    {
        cout<<a[i]<<" ";
        for(j=0;j<=n;j++)
            cout<<l[i][j]<<" ";
        cout<<'\n';
    }*/
    for(i=m,j=n;i;)
    {
        if(a[i]==b[j]) { sol[++nrsol]=a[i]; i--;j--; }
        else if(l[i-1][j]<l[i][j-1]) j--; else i--;
    }
    fout<<l[m][n]<<'\n';
    for(i=nrsol;i>=1;i--)
     fout<<sol[i]<<" ";
    return 0;
}
