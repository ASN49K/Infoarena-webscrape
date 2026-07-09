#include <fstream>
#include <vector>

inline int max(int a, int b)
{
    if(a > b) return a;
    return b;
}

int lcs(int **nC, int *nX, int *nY, int m, int n);

void bt(int **nC, int *nX, int *nY, int i, int j, std::vector<int> &myV);

int main()
{
    std::ifstream in("cmlsc.in");
    std::ofstream out("cmlsc.out");

    int *nA, *nB, nV1, nV2;

    in >> nV1 >> nV2;

    nA = new int[nV1 + 1];
    nB = new int[nV2 + 1];

    for(int i = 1; i <= nV1; i++)
        in >> nA[i];
    for(int i = 1; i <= nV2; i++)
        in >> nB[i];

    int **nC = new int*[nV1 + 1];

    for(int i = 0; i <= nV1; i++)
        nC[i] = new int[nV2 + 1];

    std::vector<int> myV;

    out << lcs(nC, nA, nB, nV1, nV2) << '\n';

    bt(nC, nA, nB, nV1, nV2, myV);

    for(unsigned i = 0; i < myV.size(); i++)
        out << myV[i] << ' ';

    return 0;
}

int lcs(int **nC, int *nX, int *nY, int m, int n)
{
    for(int i = 0; i <= m; i++)
        nC[i][0] = 0;
    for(int i = 0; i <= n; i++)
        nC[0][i] = 0;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(nX[i] == nY[j])
                nC[i][j] = nC[i - 1][j - 1] + 1;
            else
                nC[i][j] = max(nC[i][j - 1], nC[i - 1][j]);
    return nC[m][n];
}

void bt(int **nC, int *nX, int *nY, int i, int j, std::vector<int> &myV)
{
    if(i == 0 || j == 0)
        return;
    else if(nX[i] == nY[j])
        {
            bt(nC, nX, nY, i - 1, j - 1, myV);
            myV.push_back(nX[i]);
        }
    else if(nC[i][j - 1] > nC[i - 1][j])
        bt(nC, nX, nY, i, j - 1, myV);
    else
        bt(nC, nX, nY, i - 1, j, myV);
}
