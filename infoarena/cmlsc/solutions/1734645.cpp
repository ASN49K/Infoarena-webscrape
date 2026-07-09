#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


# define NMAX 1025

int a[NMAX],b[NMAX],sol[NMAX],mat[NMAX][NMAX];

int main()
{
    int n,m;
    int i,j,k=0;

    fin >> n >> m;

    for(i=1;i<=n;i++)
    {
        fin>>a[i]; //citesc șirul a
    }

    for(j=1;j<=m;j++)
    {
        fin>>b[j]; //citesc șirul b
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                mat[i][j]=mat[i-1][j-1]+1;       //mat[x][y] = cel mai lung subsir de la 1..x la 1..y
            }
            else
               {
                   mat[i][j]=max(mat[i][j-1],mat[i-1][j]);

               }
        }
    }
    fout<<mat[n][m]<<'\n';
    for(i=n, j=m; i>0, j>0;)
    {
        if(a[i]==b[j])
        {
            sol[++k]=a[i];
            i--;
            j--;
        }
        else
        {
            if(mat[i][j-1]>mat[i-1][j])
                j--;
            else
                i--;
        }
    }
    ++k;
    while (--k)
    {
        fout<<sol[k]<<" ";
    }

}
