#include <fstream>
#define NMAX 1100

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int i, n, m, j;
int A[NMAX], B[NMAX];
int M[NMAX][NMAX];
int sol[NMAX*NMAX];

int main()
{   fin>>m>>n;
    for(i=1; i<=m; i++)
        fin>>A[i];
    for(i=1; i<=n; i++)
        fin>>B[i];
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(A[i]==B[j])
                M[i][j]=M[i-1][j-1]+1;
                else
                M[i][j]=max(M[i-1][j], M[i][j-1]);
    fout<<M[m][n]<<'\n';
    i=m; j=n; int k=0;
    while(i>0 && j>0)
        {if(A[i]==B[j])
            {sol[k++]=A[i]; i--; j--;}
            else
            {if(M[i-1][j]>M[i][j-1]) i--; else j--;}
        }
    for(k=k-1; k>=0; k--)
        fout<<sol[k]<<' ';
    fout<<'\n';
    fin.close();
    fout.close();
    return 0;
}
