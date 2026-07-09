#include <iostream>

using namespace std;

int d[1025][1025]={};

int main()
{
    int m,n;
    cin >> m >> n;
    int A[m+1];
    int B[n+1];
    for(int i = 1; i <= m; i++)
        cin >> A[i];
    for(int i = 1; i <= n; i++)
        cin>>B[i];
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
    cout<<d[m][n]<<endl;
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
        cout << sol[i] << " ";
    return 0;
}
