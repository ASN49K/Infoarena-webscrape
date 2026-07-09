#include <iostream>
#include <fstream>
#define NMAX 1025
using namespace std;
int a[NMAX],b[NMAX],p[NMAX][NMAX],s[NMAX];
int main()
{
    int n,m,i,j,k=0;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                p[i][j]=1+p[i-1][j-1];
            else
                p[i][j]=max(p[i-1][j],p[i][j-1]);
    for(i=n,j=m;i>=1 && j>=1;)
    {
        if(a[i]==b[j])
        {
            s[k++]=a[i];
            i--;j--;
        }
        else if(p[i-1][j]>p[i][j-1]) i--;
        else j--;

    }
    g<<p[n][m]<<"\n";
    for(i=k-1;i>=0;i--)
        g<<s[i]<<" ";
    f.close();
    g.close();
}
