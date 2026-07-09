#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in") ;
ofstream fout("cmlsc.out") ;

int n , m , v[1030] , a[1030] , c[1030] , i , j , d[1030][1030] , k;

int main()
{
    fin >> n >> m ;
    for(int i=1; i<=n; i++)
        fin >> v[i] ;
    for(int i=1; i<=m; i++)
        fin >> a[i] ;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
    {
        if(v[i] == a[j])
            d[i][j] = d[i-1][j-1] + 1 ;
        else
            d[i][j] = max(d[i-1][j] , d[i][j-1]) ;
    }
    fout << d[n][m] << "\n" ;
    i = n ; j = m ;
    while(i>=1 && j>=1 && d[i][j] != 0)
        {
            if(v[i] == a[j])
            {
                k ++ ;
                c[k] = a[j] ;
                i--;
                j--;
            }
            else if (d[i-1][j] < d[i][j-1])
                j-- ;
            else
                i-- ;
        }
     for(i=k; i>=1; i--)
        fout << c[i] << " ";

    return 0;
}
