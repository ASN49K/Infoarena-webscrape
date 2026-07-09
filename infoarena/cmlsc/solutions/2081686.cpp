#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,k,a[1025],b[1025],l[1025][1025],sol[1025];
int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(j=1; j<=m; j++)
        f>>b[j];
    for(i=0; i<=n; i++)
        for(j=0; j<=m; j++)
        {
            if(i==0 or j==0)
                l[i][j]=0;
            else
                if(a[i]==b[j])
                    l[i][j]=1+l[i-1][j-1];
                else
                    if(l[i-1][j]>l[i][j-1])
                        l[i][j]=l[i-1][j];
                    else
                        l[i][j]=l[i][j-1];
        }
    i=n;
    j=m;
    k=0;
    while(i)
    {
        if(a[i]==b[j])
            {
                sol[++k]=a[i];
                i--;
                j--;
            }
        else
            if(l[i-1][j]>l[i][j-1])
                        i--;
                    else
                        j--;
    }
    g<<l[n][m]<<endl;
    for(i=k-1;i>=1;i--)
        g<<sol[i]<<" ";
}
