#include <fstream>
#define in "cmlsc.in"
#define out "cmlsc.out"
#define NM 1030

using namespace std;

ifstream fin(in);
ofstream fout(out);

short A[NM],B[NM];
int n,m;

short v[NM][NM];

void afisare()
{
    for(int j=1; j<=m; ++j)
    {
        for(int i=1; i<=n; ++i)
            fout<<v[i][j]<<" ";
        fout<<"\n";
    }
}

inline void Afis(int i,int j)
{
    if(i > 0 && j > 0)
    {
        if(A[i] == B[j])
        {
            Afis(i-1,j-1);
            fout<<A[i]<<" ";
        }
        else if(v[i-1][j] == v[i][j]) Afis(i-1,j);
        else Afis(i,j-1);
    }
}

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; ++i)
        fin>>A[i];
    for(int j=1; j<=m; ++j)
        fin>>B[j];

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            if(A[i] == B[j])
                v[i][j] = v[i-1][j-1] + 1;
            else
                v[i][j] = max(v[i][j-1],v[i-1][j]);
        }
    fout<<v[n][m]<<"\n";

    Afis(n,m);


    fin.close(); fout.close();
    return 0;
}
