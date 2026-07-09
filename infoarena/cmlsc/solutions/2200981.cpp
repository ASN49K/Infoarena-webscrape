#include <fstream.h>

using namespace std;

int A[1025], B[1025], M, N, fSol[1025], maxs = 0;

struct
{
    int c, p;
}pSol[1025];

bool Cond(int x)
{
    int i;
    for (i = 1; i <= x - 1; i++)
        if (pSol[i].c == pSol[x].c)
            return false;
    if (x > 1)
        if (pSol[x - 1].p >= pSol[x].p)
            return false;
    return true;
}

bool Sol(int x, int k)
{
    return x == k;
}

bool subSir(int x)
{
    int i = 1, j = 1;
    while (i <= x && j <= N)
    {
        if (pSol[i].c == B[j])
            i++;
        j++;
    }
    if (i > x)
        return true;
    return false;
}

void backTracking(int x, int k)
{
    int i, j, z;
    for (i = 1; i <= M; i++)
    {
        pSol[x].c = A[i];
        pSol[x].p = i;
        if (Cond(x) == true)
            if (Sol(x, k) == true)
            {
                if (subSir(x) == true)
                    if (x > maxs)
                    {
                        maxs = x;
                        for (j = 1; j <= x; j++)
                            fSol[j] = pSol[j].c;
                    }
            }
            else
                backTracking(x + 1, k);
    }
}

int main()
{
    int i;
    ifstream fIn("cmlsc.in");
    fIn >> M >> N;
    for (i = 1; i <= M; i++)
        fIn >> A[i];
    for (i = 1; i <= N; i++)
        fIn >> B[i];
    fIn.close();
    for (i = 1; i <= M; i++)
        backTracking(1, i);
    ofstream fOut("cmlsc.out");
    fOut << maxs << endl;
    for (i = 1; i <= maxs; i++)
        fOut << fSol[i] << ' ';
    fOut.close();
}
