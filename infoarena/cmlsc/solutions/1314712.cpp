#include <fstream>
#include <iostream>
using namespace std;

ifstream is("cmlsc.in");
ofstream os("cmlsc.out");

int x[1030], y[1030], A[1030][1030];
int n, m;
int cnt;
int cn = 1;

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
    os << A[n][m] << endl;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(A[i][j] == cn && cn <= cnt)
            {
                os << x[i] << " ";
                cn++;
            }
    is.close();
    os.close();
    return 0;
}
