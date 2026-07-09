#include <iostream>
#include <fstream>

using namespace std;

#define LMAX 1024

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
unsigned short A[LMAX + 1], B[LMAX + 1], tab[LMAX + 1][LMAX + 1];

void subsir(int i, int j)
{
    if(i != 0 && j != 0)
    {
        if(tab[i][j] == tab[i - 1][j])
            subsir(i - 1, j);
        else if(tab[i][j] == tab[i][j - 1])
            subsir(i, j - 1);
        else
        {
            subsir(i - 1, j - 1);
            g << A[i] << ' ';
        }
    }
}

int main()
{
    unsigned short M, N;
    f >> M >> N;
    for(unsigned short i = 1; i <= M; i++)
        f >> A[i];
    for(unsigned short i = 1; i <= N; i++)
        f >> B[i];
    f.close();

    for(unsigned short i = 1; i <= M; i++)
        for(unsigned short j = 1; j <= N; j++)
        {
            if(A[i] == B[j])
                tab[i][j] = tab[i - 1][j - 1] + 1 ;
            else if(tab[i - 1][j] > tab[i][j - 1])
                tab[i][j] = tab[i - 1][j];
            else
                tab[i][j] = tab[i][j - 1];
        }

    g << tab[M][N] << '\n';
    subsir(M, N);
    return 0;
}
