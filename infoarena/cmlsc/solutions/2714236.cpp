#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmslc.in");
ofstream fout("cmslc.out");
int d[1028][1028]={};

int main()
{
    int m,n;
    fin >> m >> n;
    int A[1028];
    int B[1028];
    for(int i = 1; i <= m; i++)
        fin >> A[i];
    for(int i = 1; i <= n; i++)
        fin>>B[i];
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if( A[i] == B[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = max( d[i-1][j] , d[i][j-1] );
        }
    }
    fout<<d[m][n]<<endl;
    int sol[d[m][n]+1];
    for(int i = m, j = n; i >= 1 && j >=1; )
    {

        if(A[i] == B[j])
        {
            sol[d[i][j]] = A[i];
            --i;
            --j;
        }
        else if(d[i][j] == d[i-1][j] )
            --i;
        else
            --j;
    }
    for(int i = 1; i <= d[m][n]; i++)
        fout << sol[i] << " ";
    return 0;
}
