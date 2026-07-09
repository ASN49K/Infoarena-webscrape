#include <fstream>
#include <cstdlib>

using namespace std;

const int NMAX = 1025;

int v[3][NMAX];
int dp[NMAX][NMAX];

inline int max(const int& x, const int& y) {return x >= y ? x : y;}
int main()
{
    int i, j, k;
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    in >> v[0][0] >> v[1][0];
    for(i = 0; i < 2; ++i)
    {
        for(j = 1; j <= v[i][0]; ++j)
        {
            in >> v[i][j];
        }
    }
    for(i = 1; i <= v[0][0]; ++i)
    {
        for(j = 1; j <= v[1][0]; ++j)
        {
            if(v[0][i] == v[1][j]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else                   dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    k = v[2][0] = dp[i = v[0][0]][j = v[1][0]];
    while(i && j)
    {
        if(v[0][i] == v[1][j])
        {
            v[2][k--] = v[0][i--];
            --j;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]) --i;
        else --j;
    } 
    
    out << v[2][0] << '\n';
    for(i = 1; i <= v[2][0]; ++i)
    {
        out << v[2][i] << ' ';
    }

    return EXIT_SUCCESS;
}
