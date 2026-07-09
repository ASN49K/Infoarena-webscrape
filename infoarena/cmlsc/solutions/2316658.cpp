#include <bits/stdc++.h>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int a[1025],b[1025],i,j,bst,d[1025][1025],sir[1025],n,m;
int main()
{
    fin>>m>>n;
    for(i = 1; i <= m ; i++)
        fin>>a[i];
    for(i = 1; i <= n ; i++)
        fin>>b[i];

    for(i = 1 ; i <= m; i++)
        for( j = 1 ; j <= n; j++)
            if (a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);

    for (i = m, j = n; i;)
        if (a[i] == b[j])
            sir[++bst] = a[i], --i, --j;
        else if (d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;
      fout<<bst<<endl;
      for(i=bst;i>=1;i--)fout<<sir[i]<<' ';
    return 0;
}
