#include <cstdlib>
#include <fstream>

using namespace std;

const int NMAX = 1111;

int v[3][NMAX];
int dp[NMAX][NMAX];

inline int _max(const int& x, const int& y) {return x > y ? x : y;}
int main()
{
    int i, j, k;
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    in >> v[0][0] >> v[1][0];
    for(i = 1; i <= v[0][0]; ++i) in >> v[0][i];
    for(i = 1; i <= v[1][0]; ++i) in >> v[1][i];

    for(i = 1; i <= v[0][0]; ++i)
    {
	for(j = 1; j <= v[1][0]; ++j)
	{
	    if(v[0][i] == v[1][j]) dp[i][j] = dp[i - 1][j - 1] + 1;
	    else                   dp[i][j] = _max(dp[i][j - 1], dp[i - 1][j]);
	}
    }

    for(i = v[0][0], j = v[1][0], k = v[2][0] = dp[i][j]; i && j;)
    {
	if(v[0][i] == v[1][j]) v[2][k--] = v[0][i--], --j;
	else if(dp[i][j - 1] > dp[i - 1][j]) --j;
	else                                 --i;
    }

    out << v[2][0] << '\n';
    for(i = 1; i <= v[2][0]; ++i) out << v[2][i] << ' ';
    out << '\n';
    
    return EXIT_SUCCESS;
}
