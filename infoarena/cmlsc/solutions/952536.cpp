#include<fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAXN = 1030;
int a[MAXN], b[MAXN], v[MAXN], N, M, d[MAXN][MAXN];

inline int maxim(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int main()
{
    int i, j, k=0, aux, l=0;
    fin >> N >> M;
    for(i=1; i<=N; ++i)
        fin >> a[i];
    for(i=1; i<=M; ++i)
        fin >> b[i];

    for(i=1; i<=M; ++i){
        for(j=1; j<=N; ++j)
        {
            if(a[j] == b[i])
                d[i][j] = 1+ d[i-1][j-1];
            else
                d[i][j] = maxim(d[i][j-1], d[i-1][j]);
        }
    }

    j = 1;
    aux = d[M][N];
    for(i=1; i<=N; ++i)
    {
        if(d[M][i] == j)
        {
            l++;
            v[++k] = a[i];
            ++j;
        }
        if(j > aux)
            break;
    }
    fout << l << "\n";

    for(i=1; i<=k; ++i)
        fout << v[i] << " ";

    fin.close();
    fout.close();

    return 0;
}
