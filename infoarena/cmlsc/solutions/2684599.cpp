#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int d[1025][1025],a[1025],b[1025],sol[1025];

int main()
{
    int n,m,i,j,e;
    in >> n >> m;
    for(i=1; i<=n; i++)
        in >> a[i];
    for(i=1; i<=m; i++)
        in >> b[i];
    for( i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
                d[i][j] = d[i-1][j-1]+1;
            else
            {
                if(d[i-1][j] > d[i][j-1])
                    d[i][j] = d[i-1][j];
                else
                    d[i][j] = d[i][j-1];
            }
    i=n;
    j=m;
    e=0;
    while(i>0 && j>0)
    {
        if(a[i] == b[j])
        {
            sol[e]=a[i];
            e++;
            i--;
            j--;
        }
        else
        {
            if(d[i-1][j]>d[i][j-1])
               i--;
            else
               j--;
        }
    }
    out << d[n][m] << endl;
    for( int e1=e-1; e1>=0 ;e1--)
        out << sol[e1] << " ";
    return 0;
}
