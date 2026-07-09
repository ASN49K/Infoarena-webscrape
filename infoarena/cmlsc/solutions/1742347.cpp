#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


int m, n, a[1025], b[1025], M[1025][1025], sol[1025],k,i,j;

int main()
{
    int i, j;

    fin>>m>>n;

    for(i=1; i<=m; i++)
        fin>>a[i];

    for(i=1; i<=n; i++)
        fin>>b[i];



    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)

            if (a[i] == b[j])
                M[i][j] = 1 + M[i-1][j-1];

            else
                M[i][j] = max(M[i-1][j], M[i][j-1]);


    i=m;
    j=n;

    while(i>0 && j>0 )
    {
        if(M[i][j]== max(M[i-1][j], M[i][j-1]) )
            if(M[i-1][j]>M[i][j-1]) --i;
            else --j;

        else
        {
            sol[++k]=a[i];
            --i;
            --j;
        }
    }

    fout<<M [m][n]<<'\n';
    for(i=k; i>=1; i--) fout<<sol[i]<<" ";
    return 0;
}
