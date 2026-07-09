#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int NMAX=1050;
int T[NMAX][NMAX];
int A[NMAX],B[NMAX],N,M,Result[NMAX],L=0;
void Afisare_Subsir(int i, int j)
{
    if (i!=0&&j!=0)
    {
    if (A[i]==B[j])
    {
        Result[++L]=A[i];
        Afisare_Subsir(i-1,j-1);
    }
    else
    {
        if (T[i-1][j]>T[i][j-1])
            Afisare_Subsir(i-1,j);
        else Afisare_Subsir(i,j-1);
    }
    }
}
int main()
{
    fin>>N>>M;
    for (int i=1; i<=N; i++)
        fin>>A[i];
    for (int i=1; i<=M; i++)
        fin>>B[i];
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
        if (A[i]==B[j])
        T[i][j]=T[i-1][j-1]+1;
        else T[i][j]=max(T[i-1][j],T[i][j-1]);
        fout<<T[N][M]<<"\n";
        Afisare_Subsir(N,M);
        for (int i=L; i>=1; i--)
            fout<<Result[i]<<" ";
        return 0;
}
