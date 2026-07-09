#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NLIM = 1024 + 10;

int N, M;

int v[2][NLIM];
int mat[NLIM][NLIM];


int main()
{
    fin >> N >> M;
    for( int i = 1; i <= N; ++i )
        fin >> v[0][i];
    for( int i = 1; i <= M; ++i )
        fin >> v[1][i];



    for( int i = 1; i <= N; ++i )
    {
        for( int j = 1; j <= M; ++j )
        {
            mat[i][j] = max( mat[i][j - 1], max( mat[i - 1][j], mat[i - 1][j - 1] + ( v[0][i] == v[1][j] ) ) );
            //cout << mat[i][j] << " ";
        }
       // cout << "\n";
    }


    stack< int > res;
    int x = N, y = M;
    while( res.size() < mat[N][M] )
    {
        while( mat[x][y] == mat[x - 1][y] )
            --x;
        while( mat[x][y] == mat[x][y - 1] )
            --y;
        res.push( v[0][x] );
        --x;
        --y;
    }

    fout << mat[N][M] << "\n";
    while( res.size() )
    {
        fout << res.top() << " ";
        res.pop();
    }
    fout << "\n";
    return 0;
}
