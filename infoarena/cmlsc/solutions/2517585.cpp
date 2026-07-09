#include <bits/stdc++.h>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int n, m;
int v[1030], w[1030];
int a[1030][1030];
int main()
{
    fin >> n >> m;
    for ( int i = 1 ; i <= n ; i++ )
        fin >> v[i];
    for ( int i = 1 ; i <= m ; i++ )
        fin >> w[i];
    int nr = 0;
    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= m ; j++ )
        {
            a[i][j] = max(a[i-1][j],a[i][j-1]);
            if ( v[i] == w[j] )
                a[i][j] = max(a[i][j], a[i-1][j-1] + 1);
        }
    }
    fout << a[n][m] << endl;

    nr = 0;
    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= m ; j++ )
        {
           if ( a[i][j] == (nr + 1) && v[i] == w[j] )
           {
               fout << v[i] << " ";
               nr++;
           }
        }
    }


    /*
    for(int i = nr ; nr > 0; nr --)
    {

    }
    */

    return 0;
}
