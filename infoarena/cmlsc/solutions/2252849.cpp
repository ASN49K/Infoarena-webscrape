#include <bits/stdc++.h>

using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int n, m, d[1025][1025], a[1025], b[1025], sol[1025];

int main()
{
    in >> n >> m;
    for (int i=1; i<=n; i++)
        in >> a[i];
    for (int j=1; j<=m; j++)
        in >> b[j];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    for (int i=n, j=m; i && j; )
        if (a[i]==b[j])
        {
            sol[0]++;
            sol[sol[0]]=a[i];
            i--;
            j--;
        }
        else
            if (d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;
    out << sol[0] << '\n';
    for (int i=sol[0]; i; i--)
        out << sol[i] << " ";
    return 0;
}
