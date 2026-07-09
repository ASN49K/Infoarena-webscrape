#include<fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAXN = 1030;
int a[MAXN], b[MAXN], v[MAXN], N, M, d[MAXN][MAXN], k;

inline int maxim(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

void drum(int i, int j)
{
    if(i==0 || j==0)
    {
        fout << k << "\n";
        return;
    }
    if(a[j] == b[i])
    {
        ++k;
        drum(i-1, j-1);
        fout << a[j] << " ";
    }
    else if(d[i-1][j] > d[i][j-1])
        drum(i-1, j);
    else
        drum(i, j-1);
}

int main()
{
    int i, j, aux, l=0;
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

    drum(M, N);

    fin.close();
    fout.close();

    return 0;
}
