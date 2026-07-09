#include <iostream>
#include <fstream>


using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define MAX = 1050
int index, n, m, a[MAX][MAX];
int p[MAX], q[MAX], sir[MAX];
int L[MAX][MAX];

void LCS(int p[],int q[],int n, int m)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(p[i]==q[j])
            {
                L[i][j] = 1 + L[i-1][j-1];
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
