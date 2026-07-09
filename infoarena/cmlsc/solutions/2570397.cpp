#include <iostream>
#include <fstream>
using namespace std;

int A[1030], B[1030], D[1030][1030], n, m, k, sol[1030];
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>A[i];
    }
    for(int j=1;j<=m;j++)
    {
        fin>>B[j];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(A[i] == B[j])
            {
                D[i][j] = D[i-1][j-1] + 1;
            }
            else
            {
                D[i][j] = max(D[i-1][j], D[i][j-1]);
            }
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        {
            if(A[i] == B[j])
            {
                sol[++k] = A[i];
            }
            else if (D[i][j-1] < D[i-1][j])
                i--;
            else
                j--;
        }
    }
    fout<<k<<'\n';
    for(int i=k;i>=1;i--)
        fout<<sol[i]<<' ';
}
