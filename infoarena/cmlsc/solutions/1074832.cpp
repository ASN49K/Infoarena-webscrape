#include <fstream>

#define NMax 260
using namespace std;
int M, N, A[NMax], B[NMax], sir[NMax], bst, sol[NMax];

int subsir(int nr) // daca sir[1..nr] este subsir pentru B[1..N]
{
    int i, j = 1;

    for (i = 1; i <= nr && j <= N; i++)
        for (; j <= N && B[j] != sir[i]; ++j);
    return j <= N;
}

void back(int nivel, int len)
{
    int i;

    if (nivel == M+1)
    {
        if (subsir(len)) // daca sir este subsir si pentru B
            if (len > bst)
            {
                bst = len;
                for (i = 1; i <= bst; i++)
                    sol[i] = sir[i];
            }

        return ;
    }

    // nu folosim A[nivel]
    back(nivel+1, len);
    // folosim A[nivel] in solutie
    sir[len+1] = A[nivel]; back(nivel+1, len+1);
}

int main()
{
    int i;

    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    fin>>M>>N;
    for (i = 1; i <= M; i++)
        fin>>A[i];
    for (i = 1; i <= N; i++)
        fin>>B[i];

    back(1, 0);

    fout<<bst<<"\n";
    for (i = 1; i <= bst; i++)
        fout<<sol[i];

    return 0;
}
