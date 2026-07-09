//foloseste programare dinamica

#include <fstream>
#define maxim(a,b) (a > b) ? a : b
#define NMax 1025
using namespace std;

int a[NMax], b[NMax], c[NMax][NMax], i, j, N, M, sol[NMax], k;

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    fin >> N >> M;

    for(i = 1 ; i <= N ; ++i)
        fin >> a[i];

    for(i = 1 ; i <= M ; ++i)
        fin >> b[i];

    for(i = 1 ; i <= N ; ++i)
        for(j = 1 ; j <= M ; ++j)
            if(a[i] == b[j])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = maxim(c[i-1][j], c[i][j-1]);
    fout << c[N][M] << '\n';

    for(i = N, j = M ; i ;)
        if(a[i] == b[j])
            sol[++k] = a[i], --i, --j;
        else
        {
            if(c[i-1][j] < c[i][j-1])
                --j;
            else
                --i;
        }

    for(i = k ; i ; --i)
            fout << sol[i] << ' ';

    fin.close();
    fout.close();
    return 0;
}
