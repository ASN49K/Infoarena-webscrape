#include <fstream>

using namespace std;

ifstream fin ("cmlcs.in");
ofstream fout ("cmlcs.out");


int n, m;
int a[1030], b[1030];
int L[1030][1030];

void citire();
void pd();

int main()
{
    citire();
    pd();
    return 0;
}

void citire()
{
    int i;
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        fin>>a[i];
    for(i=1; i<=m; ++i)
        fin>>b[i];
}

void pd()
{
    int i, j;
    for(i=n; i>=1; --i)
    {
        for(j=m; j>=1; --j)
            if(a[i]==b[j])
            L[i][j]=1+L[i+1][j+1];
            else L[i][j]=max(L[i+1][j], L[i][j+1]);
    }
    fout<<L[1][1]<<'\n';
    for(i=1, j=1; i<=n && j<=n; )
    {
        if(a[i]==b[j])
        {
            fout<<a[i]<<' ';
            ++i;
            ++j;
        }
        else if( L[i][j+1]>L[i+1][j] ) ++j;
        else ++i;
    }
}
