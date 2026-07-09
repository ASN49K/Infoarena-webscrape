#include <fstream>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#define N_MAX 1031

using namespace std;

int v[3][N_MAX];
int dp[N_MAX][N_MAX];

inline int _max(int x, int y) {return x >= y ? x : y;}
int main()
{
    int i, j, k;
    ifstream in( "cmlsc.in" );
    ofstream out( "cmlsc.out" );

    in>>v[0][0]>>v[1][0];
    for(i=1; i <= v[0][0]; ++i)
        in>>v[0][i];
    for(i=1; i <= v[1][0]; ++i)
        in>>v[1][i];
    for(i=1; i <= v[0][0]; ++i)
        for(j=1; j <= v[1][0]; ++j)
            if( v[0][i] == v[1][j] )
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else dp[i][j]=_max(dp[i][j-1], dp[i-1][j]);
    v[2][0]=dp[v[0][0]][v[1][0]];
    for(i=v[0][0], j=v[1][0], k=v[2][0]; i && j; )
        if( v[0][i] == v[1][j] )
            v[2][k]=v[0][i], --k, --i, --j;
        else if( dp[i-1][j] >= dp[i][j-1] )
                 --i;
             else --j;
    out<<v[2][0]<<'\n';
    copy(v[2]+1, v[2]+v[2][0]+1, ostream_iterator<int>(out, " ") );
    out<<'\n';

    return EXIT_SUCCESS;
}
