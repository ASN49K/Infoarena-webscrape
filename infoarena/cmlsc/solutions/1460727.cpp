/** Care este cel mai lung subsir comun dintre sirurile a si b?
Solutia: Programare dinamica pe o matrice D;
Complexitate: O(N*M);
In sirul s se alfa raspunsul.
**/
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAX = 1024;
vector<int> a;
vector<int> b;
vector<int> s;
int N, M;
int D[MAX][MAX];
int x;
int ns;

int main()
{
    int i, j;

    fin >> N >> M;
    a.push_back(0);
    b.push_back(0);
    for ( i = 1; i <= N; i++ )
    {
        fin >> x;
        a.push_back(x);
    }
    for ( i = 1; i <= M; i++ )
    {
        fin >> x;
        b.push_back(x);
    }

    a.resize(N + 1);
    b.resize(M + 1);

    memset( D, 0, sizeof(D) );

    for ( i = 1; i <= N; i++ )
        for ( j = 1; j <= M; j++ )
            if ( a[i] == b[j] )
                D[i][j] = D[i - 1][j - 1] + 1;
            else
                D[i][j] = max( D[i - 1][j], D[i][j - 1] );

    for ( i = N, j = M; i; )
        if ( a[i] == b[j] )
            s.push_back(a[i]), i--, j--, ns++;
        else
            if ( D[i - 1][j] > D[i][j - 1] )
                i--;
            else
                j--;

    s.resize(ns);

    fout << D[N][M] << '\n';
    for ( i = ns - 1; i > -1; i-- )
        fout << s[i] << ' ';

    fin.close();
    fout.close();
    return 0;
}
