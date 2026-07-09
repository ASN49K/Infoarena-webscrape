#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,a[1030],b[1030],d[1030][1030],afis[1030],ind;

void citire()
{
    f>>n>>m;
    for (int i = 1; i <= n; ++i)
        f>>a[i];
    for (int i = 1; i <= m; ++i)
        f>>b[i];
}

int main() {
    citire();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    for (int i = n,j=m; i&&j ; )
        if(a[i]==b[j])
        {
            afis[ind++]=a[i];
            i--;
            j--;
        } else if (d[i][j-1]<d[i-1][j])
            i--;
        else
            j--;
    g<<ind<<'\n';
    for (int i = ind-1; i >= 0; --i)
        g<<afis[i]<<' ';
    return 0;
}
