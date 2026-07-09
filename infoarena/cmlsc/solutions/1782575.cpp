#include <cstdio>
using namespace std;

FILE* is = fopen("cmlsc.in", "r");
FILE* os = fopen("cmlsc.out", "w");

int A[1025], B[1025], K[1025], subsir[1025];
int n, m, mx;

void Read();
void Back(int k, int nr);
void Print(int nr);
bool Subsir(int nr);

int main()
{
    Read();
    Back(1, 1);
    fprintf(os, "%d\n", mx);
    for ( int i = 1; i <= mx; ++i )
        fprintf(os, "%d ", subsir[i]);
    fclose(is);
    fclose(os);
    return 0;
}
void Read()
{
    fscanf(is, "%d%d", &n, &m);
    for ( int i = 1; i <= n; ++i )
        fscanf(is, "%d", &A[i]);
    for ( int i = 1; i <= m; ++i )
        fscanf(is, "%d", &B[i]);
}
void Back(int k, int nr)
{
    if ( k > n )
        return;
    //iau pe A[k]
    //nr creste
    K[nr] = A[k];
    if ( Subsir(nr) )
    {
        if ( nr > mx )
        {
            mx = nr;
            for ( int i = 1; i <= mx; ++i )
                subsir[i] = K[i];
        }
    }
    Back(k+1, nr+1);

    //nu iau pe A[k]
    Back(k+1, nr);
}
void Print(int nr)
{
    for (int i = 1; i <= nr; ++i )
        fprintf(os, "%d ", K[i]);
    fprintf(os, "\n");
}
bool Subsir(int nr) // daca K e subsir a lui B
{
    int j = 1;
    for ( int i = 1; i <= nr; ++i )
        for(; K[i] != B[j]; ++j)
            if ( j > m )
                return false;
    return true;
}
