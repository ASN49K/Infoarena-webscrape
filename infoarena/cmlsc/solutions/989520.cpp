#include <iostream>
#include <fstream>

using namespace std;

int m,n,a[1025],b[1025],i,j,d[1025][1025],sir[1025],l;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(i=1;i<=n;i++)
        f>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                if(d[i-1][j]>d[i][j-1])
                    d[i][j]=d[i-1][j];
                else
                    d[i][j]=d[i][j-1];
    for(i=m,j=n;i;)
        if(a[i]==b[j])
        {
            sir[++l]=a[i];
            i--;
            j--;
        }
        else
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;
    g<<l<<"\n";
    for(i=l;i>=1;i--)
        g<<sir[i]<<" ";
    return 0;
}
