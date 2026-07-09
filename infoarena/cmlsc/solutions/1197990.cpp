#include <fstream>

using namespace std;

ifstream in("rmq.in");
ofstream out("rmq.out");

const int lmax = 100001 , loglmax = 16;

int n , m , r[loglmax][lmax] , lg[lmax];

int main()
{
    int i , j , a , b , L;

    in >> n >> m >> r[0][1];

    for(i = 2 ; i <= n ; i++)
    {
        in >> r[0][i];
        lg[i] = 1 + lg[i / 2];
    }

    for(i = 1 ; i <= loglmax ; i++)
        for(j = 1 ; j <= n ; j++)
        {
            r[i][j] = r[i - 1][j];

            if(j > (1 << (i - 1)) && r[i][j] > r[i - 1][j - (1 << (i - 1))])
                r[i][j] = r[i - 1][j - (1 << (i - 1))];
        }

    for(i = 1 ; i <= m ; i++)
    {
        in >> a >> b;

        L = lg[b - a + 1];
        out << min(r[L][b] , r[L][a + (1 << (L - 1))]) << '\n';
    }
    return 0;
}
