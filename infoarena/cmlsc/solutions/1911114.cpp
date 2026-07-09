#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N,M;
int A[1030];
int B[1030];
int Comun[1030][1030];
int NrComun[1030][1030];

void Calcul(int i,int j)
{
    if (i == 0 || j == 0)
        return;
    else
    {
        if (Comun[i][j])
        {
            fout<<A[i]<<' ';
            Calcul(i-1,j-1);
        }
        else
            if(NrComun[i-1][j] > NrComun[i][j-1])
                Calcul(i-1,j);
            else
                Calcul(i,j-1);
    }
}


int main()
{
    fin >> N >> M;
    for (int i = 1; i <= N; i++)
        fin>>A[i];
    for (int i = 1; i <= M; i++)
        fin>>B[i];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if(A[i] == B[j])
            {
                NrComun[i][j] = NrComun[i-1][j-1] + 1;
                Comun[i][j] = 1;
            }
            else
                NrComun[i][j] = max(NrComun[i-1][j],NrComun[i][j-1]);
    fout<<NrComun[N][M]<<'\n';

}
