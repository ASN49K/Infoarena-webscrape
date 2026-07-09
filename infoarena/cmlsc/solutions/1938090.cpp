#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
unsigned short int a[1025],b[1025],d[1025][1025],sol[1025],m,n,aux;
int main()
{
    fin>>m>>n;
    for(int i=1; i<=m; i++)
    {
        fin>>a[i];
        d[i][0]=0;
    }
    for(int i=1; i<=m; i++)
    {
        fin>>b[i];
        d[0][i]=0;
    }

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    int nr=d[m][n];
    fout<<nr<<'\n';
    int i=m,j=n;
    while(i && j)
        if(a[i]==b[j])
        {
            sol[nr]=a[i];
            nr--,i--,j--;
        }
        else if(d[i-1][j]>=d[i][j-1])
            i--;
        else
            j--;
    for(int i=1; i<=d[m][n]; i++)
        fout<<sol[i]<<' ';
    return 0;
}
