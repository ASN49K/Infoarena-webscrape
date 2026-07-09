#include <iostream>
#include <fstream>
using namespace std;
int puncte1[1030],puncte2[1030],tabel[1030][1030],retin[1030];
int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    int n,m,i,j,x,y,a=1;
    in>>n;
    in>>m;
    for (i=1;i<=n;i++)
    {
        in>>puncte1[i];
    }
    for (i=1;i<=m;i++)
    {
        in>>puncte2[i];
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (puncte1[i]==puncte2[j])
            {
                tabel[i][j]=tabel[i-1][j-1]+1;
            }
            else
            {
                tabel[i][j]=max(tabel[i-1][j],tabel[i][j-1]);
            }
        }
    }
    out<<tabel[n][m]<<"\n";
    x=n;
    y=m;
    for (i=1;i<=tabel[n][m];i++)
    {
        if (puncte1[x]==puncte2[y])
        {
            retin[a]=puncte1[x];
            a++;
            x--;
            y--;
        }
        else
        {
            i--;
            if (tabel[x-1][y]>tabel[x][y-1])
            {
                x--;
            }
            else
            {
                y--;
            }
        }
    }
    for (i=a-1;i>=1;i--)
    {
        out<<retin[i]<<" ";
    }
}
