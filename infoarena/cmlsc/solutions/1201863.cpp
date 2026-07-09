using namespace std;
#include <fstream>
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int Mmax=1024;
const int Nmax=1024;

int a[Mmax+5], b[Nmax+5], sir[Nmax+5];
int best[Mmax+5][Nmax+5];


int main()
{
    int i, j, m, n, lg;
    fin>>m>>n;
    for(i=0; i<m; ++i) fin>>a[i];
    for(i=0; i<n; ++i) fin>>b[i];

    if(a[0]==b[0]) best[0][0]=1;

    //completam prima linie
    for(i=1; i<n; ++i)
        if(a[0]==b[i]) best[0][i]=1;
        else best[0][i]=best[0][i-1];

    //completam prima coloana
    for(i=1; i<m; ++i)
        if(b[0]==a[i]) best[i][0]=1;
        else best[i][0]=best[i-1][0];

    //completam restul matricei
    for(i=1; i<m; ++i)
        for(j=1; j<n; j++)
        {
            if(a[i]==b[j]) best[i][j]=1+best[i-1][j-1];
            else
            {
                if(best[i-1][j]<best[i][j-1]) best[i][j]=best[i][j-1];
                else best[i][j]=best[i-1][j];
            }
        }

    fout<<best[m-1][n-1]<<'\n';

    for(i=m-1, j=n-1, lg=0; i>=0 && j>=0; )
    {
        if(a[i]==b[j]) sir[lg]=a[i], ++lg, --i, --j;
        else
        {
            if(best[i-1][j]<=best[i][j-1]) --j;
            else --i;
        }
    }
    for(i=lg-1; i>=0; --i) fout<<sir[i]<<' ';
    fout<<'\n';
    return 0;
}
