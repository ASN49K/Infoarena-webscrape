#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int LMAX=1025;
int n,m;
short v1[LMAX],v2[LMAX],d[LMAX][LMAX],sol[LMAX],lg=0;

int main()

{

    f>>m>>n;

    for(int i=1;i<=m;i++)

        f>>v1[i];

    for(int i=1;i<=n;i++)

        f>>v2[i];

    for(int i=1;i<=m;i++)

        for(int j=1;j<=n;j++)

        if(v1[i]==v2[j])

            d[i][j]=1+d[i-1][j-1];

        else

            d[i][j]=max(d[i-1][j],d[i][j-1]);

    for(int i=m,j=n;i>0;)

        if(v1[i]==v2[j])

            sol[++lg]=v1[i], i--, j--;

        else

            if(d[i-1][j]<d[i][j-1]) j--;

            else i--;

    g<<lg<<'\n';

    for(int i=lg;i>=1;i--)

        g<<sol[i]<<' ';

    return 0;

}
