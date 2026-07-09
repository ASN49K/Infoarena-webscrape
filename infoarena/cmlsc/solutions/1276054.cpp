#include <fstream>

const int NMAX = 1050;

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int N,M,v1[NMAX],v2[NMAX],d[NMAX][NMAX],sol[NMAX],contor;

int maxim(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    f >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        f >> v1[i];
    }
    for (int i = 1; i <= M; ++i)
    {
        f >> v2[i];
    }

    for(int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (v1[i] == v2[j])
            {
                d[i][j] = 1 + d[i-1][j-1];
            }
            else d[i][j] = maxim(d[i-1][j],d[i][j-1]);
        }
    }

    for (int i = N, j = M; i;)
    {
        if (v1[i] == v2[j])
        {
            sol[++contor] = v1[i];
            i--, j--;
        }
        else
        {
            if (d[i-1][j] < d[i][j-1])
                j--;
            else i--;
        }
    }

    g << contor << '\n';

    for (int i = contor; i >= 1; --i)
    {
        g << sol[i] << " ";
    }

    f.close();
    g.close();

    return 0;
}
