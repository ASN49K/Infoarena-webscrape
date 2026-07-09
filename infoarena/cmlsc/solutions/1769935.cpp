#include <iostream>
#include <fstream>

using namespace std;

int serb[1025][1025];

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    short n,m,k=1;
    short a[1025],b[1025];

    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];

    for(int i=1;i<=m;i++)
        f>>b[i];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                serb[i][j]=serb[i-1][j-1]+1;
            else
                serb[i][j]=max(serb[i-1][j],serb[i][j-1]);

        }
    }

    g<<serb[n][m];

    return 0;
}
