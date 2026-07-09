#include <fstream>
#include <iostream>
using namespace std;

ifstream is("cmlsc.in");
ofstream os("cmlsc.out");

int x[1030], y[1030], A[1030][1030];
int n, m;
int cnt;
int cn = 1;
int V[1030];

int main()
{
    is >> n >> m;
    for(int i = 1; i <= n; ++i)
        is >> x[i];
    for(int i = 1; i <= m; ++i)
        is >> y[i];

    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= m; ++j)
        {
            if(i == 0 || j == 0)
                A[i][j] = 0;
            else
                if( x[i] == y[j] )
                {
                    A[i][j] = A[i-1][j-1] + 1;
                    cnt++;
                }
                else
                    A[i][j] = max(A[i-1][j], A[i][j-1]);
        }
    /*for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= m; ++j)
            cout << A[i][j] << " ";
        cout << endl;
    }
    */
    int k = 0;
    os << A[n][m] << endl;
    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(x[i] == y[j])
        {
            V[k++] = x[i];
            i--, j--;
        }
        else
            if(A[i][j-1] > A[i-1][j])
                j--;
            else
                i--;
    }
    for(int i = k - 1; i >= 0; --i)
        os << V[i] << " ";
    is.close();
    os.close();
    return 0;
}
