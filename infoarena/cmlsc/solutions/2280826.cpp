#include <iostream>
#include <fstream>


using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

char X[500], Y[500];

int index, n, m, a[100][100];
int p[100], q[100], sir[100];
int L[100][100];

void LCS(int p[],int q[],int n, int m)
{
    int tmp;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(p[i]==q[j])
            {
                L[i][j] = 1 + L[i-1][j-1];
                tmp = p[i];
            }
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    g<<L[n][m]<<'\n';
    for (int i = n, j = m; i != 0; )
        if (p[i] == q[j])
            sir[++index] = p[i], --i, --j;
        else if (L[i-1][j] < L[i][j-1])
            --j;
        else
            --i;
    for(int i=index; i; --i)
        g<<sir[i]<<" ";

}



int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++) f>>p[i];
    for(int i=1;i<=m;i++) f>>q[i];
    LCS(p, q, n, m);
    return 0;
}
