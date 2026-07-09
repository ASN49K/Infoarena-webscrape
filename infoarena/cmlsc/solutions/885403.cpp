

#include<fstream>
#include<vector>
#include<algorithm>

#define NN 1026
#define pb push_back

using namespace std;
ofstream out("cmlsc.out");

vector< int > sol;

int lcs[NN][NN], x1[NN] , x2[NN] , n , m ;

void read();
void lc();
void wrs();

int main()
{
    read();
    lc();
    wrs();

    return 0;
}

void read()
{
    ifstream in("cmlsc.in");
    in >> n  >> m;
    for( int i=1 ; i<=n ; i++)
        in >> x1[i];

    for( int j=1 ; j<=m ; j++)
        in >> x2[j];
}

void lc()
{
    for(int i=1; i<=n ; i++)
        lcs[i][0] = 0;

    for( int j=1; j<=m ; j++)
        lcs[0][j] = 0;

    for( int i=1 ; i<=n ; i++)
        for( int j=1 ; j<=m ; j++)
            if ( x1[i] == x2[j] )
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else
                lcs[i][j] = max( lcs[i-1][j] , lcs[i][j-1] );
}

void wrs()
{
    out << lcs[n][m] << '\n';

    int i , j;

    for(i=n,j=m;i;)
    {
        if ( x1[i] == x2[j] )
        {
            sol.pb( x1[i] );
            --i;
            --j;
        }
        else
            if ( lcs[i-1][j] < lcs[i][j-1] )
                --j;
                else
                --i;
    }

        reverse( sol.begin() , sol.end() );
        for( int i=0; i<sol.size(); ++i )
            out << sol[i] << " ";
}

