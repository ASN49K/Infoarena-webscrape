#include <iostream>
#include <fstream>
#include <queue>

std::ifstream f ("cmlsc.in");
std::ofstream g ("cmlsc.out");

typedef short int sir [1025];
int nA, nB; sir A, B;

int LCS [1025][1025];
void lcs () {
    for (int i=1, j; i<=nA; i++)
    for (j=1; j<=nB; j++)
        if (A[i] == B[j])
            LCS [i][j] = 1 + LCS [i-1][j-1];
        else
            LCS [i][j] = std::max (LCS [i-1][j], LCS [i][j-1]);

    g << LCS [nA][nB];
}

std::vector <int> rez;
void determSubsir (int indexA = nA, int indexB = nB) {
    if (indexA != 0 && indexB != 0) {
        if (A [indexA] == B [indexB])
            rez. push_back (A [indexA]), determSubsir (indexA-1, indexB-1);

        else if (LCS [indexA][indexB-1] > LCS [indexA-1][indexB])
            determSubsir (indexA, indexB-1);

        else
            determSubsir (indexA-1, indexB);
    }

    else;
}

int main()
{
    f >> nA >> nB;
    for (int i=1; i<=nA; i++)
        f >> A [i];
    for (int i=1; i<=nB; i++)
        f >> B[i];

    lcs ();
    determSubsir ();

    g << '\n';
    for (int i=rez. size()-1; i>=0; i--)
        g << rez[i] << ' ';

    return 0;
}
