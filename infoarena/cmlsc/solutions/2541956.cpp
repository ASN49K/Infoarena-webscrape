#include <iostream>
#include <fstream>

using namespace std;

#define NMax 260

int M, N, A[NMax], B[NMax], sir[NMax], bst, sol[NMax];

int subsir(int nr)
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
        if (subsir(len))
            if (len > bst)
            {
                bst = len;
                for (i = 1; i <= bst; i++)
                    sol[i] = sir[i];
            }

        return ;
    }
    back(nivel+1, len);
    sir[len+1] = A[nivel]; back(nivel+1, len+1);
}

int main(void)
{
    int i;

    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    cin >> M >> N;
    for (i = 1; i <= M; i++)
        cin >> A[i];
    for (i = 1; i <= N; i++)
        cin >> B[i];

    back(1, 0);

    cout << bst;
    for (i = 1; i < bst; i++)
        cout << sol[i];
    cout << sol[bst];

    return 0;
}
