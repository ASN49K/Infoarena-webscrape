#include<fstream>
#define DMAX 1025

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int LCS[DMAX][DMAX],sir[DMAX],k;
int x[DMAX],y[DMAX];
int main()
{
    int i,j,n,m;
    in >> m >> n;
    for(i = 1; i <= m; ++i)
        in >> x[i];
    for(i = 1; i <= n; ++i)
        in >> y[i];

    for(i = 1; i <= m; ++i)
        for(j = 1; j <= n; ++j)
        {
            if(x[i] == y[j])
                LCS[i][j] = LCS[i-1][j-1] + 1;
            else
                LCS[i][j] = max(LCS[i][j-1],LCS[i-1][j]);
        }
    for(i = m, j = n; i;)
    {
        if(x[i] == y[j])
        {
            sir[++k] = x[i];
            --i;
            --j;
        }

        else
            if(LCS[i-1][j] < LCS[i][j-1])
                --j;
            else
                --i;
    }
    out << k << '\n';
    for (i = k; i != 0; --i)
    {
        out << sir[i] << ' ';
    }

}
