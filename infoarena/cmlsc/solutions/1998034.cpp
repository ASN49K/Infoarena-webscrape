#include <fstream>
#include <iostream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1030][1030];
int v[1030],z[1030],c[1030];


int main()
{
    int n,m,i,j,r,cnt=0;
    f>>n;
    f>>m;

    for(i=1;i<=n;++i)
        f>>v[i];
    for(i=1;i<=m;++i)
        f>>z[i];

    for(i=1;i<=n;++i)
        {
        cnt=0;
        for(j=1;j<=m;++j)
            {
            if(v[i]==z[j])
                {
                cnt=a[i-1][j-1]+1;
                a[i][j]=cnt ;
                }
            else if(cnt<a[i-1][j])
                {
                cnt=a[i-1][j];
                a[i][j]=cnt;
                }
            else
                a[i][j]=cnt;
            }
        }

    g<<a[n][m]<<'\n';

    r=1;
    while(i>=1 && j>=1)
        {
        if(v[i]==z[j])
            {
            c[r]=z[j];
            i--;
            j--;
            r++;
            }
        else if(a[i-1][j]>a[i][j-1])
            i--;
        else if(a[i-1][j]<a[i][j-1])
            j--;
        else
            i--;
        }

    r--;
    while(r-1)
        {
        g<<c[r]<<" ";
        r--;
        }

    return 0;
}
