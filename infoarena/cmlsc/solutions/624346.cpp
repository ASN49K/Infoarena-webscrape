#include <fstream>

using namespace std;

const int nmax = 1025;
int m[nmax][nmax], N, M;
int S1[nmax], S2[nmax], P[nmax];

ofstream fout ("cmlsc.out");

void citire()
{
    ifstream fin("cmlsc.in");
    fin >> N >> M;
    int i;
    for(i = 1; i <= N; i++)
        fin >> S1[i];
    for(i = 1; i <= M; i++)
        fin >> S2[i];
}

int main()
{
    citire();

    int i, j;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= M; j++)
        {
            if(S1[i] == S2[j])
                m[i][j] = m[i - 1][j - 1] + 1;
            else m[i][j] = max(m[i - 1][j], m[i][j - 1]);
        }

    //P - vectorul cu cel mai lung subsir comun in ordine inversa

    int x = 0;
    i = N, j = M;
    while(m[i][j] != 0)
    {
        while(m[i][j] == m[i - 1][j]) i--;
        while(m[i][j] == m[i][j - 1]) j--;

        P[++x] = S1[i];
        i--, j--;
    }
    fout << m[N][M] << "\n";
    while(x)
        fout << P[x--] << " ";


    return 0;
}
