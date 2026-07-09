#include <iostream>
#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");


# define NMAX 1025

int a[NMAX],b[NMAX],sol[NMAX],mat[NMAX][NMAX];

int main()
{
    int n,m;
    int i,j,k=0;

    in>>n>>m;

    for(i=1;i<=n;i++)
    {
        in>>a[i];
    }

    for(j=1;j<=m;j++)
    {
        in>>b[j];
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                mat[i][j]=mat[i-1][j-1]+1;
            }
            else
               {
                   mat[i][j]=max(mat[i][j-1],mat[i-1][j]);

               }
        }
    }
    out<<mat[n][m]<<'\n';
    for(i=n,j=m;i>0,j>0;)
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
    for(;k>0;k--)
    {
        out<<sol[k]<<" ";
    }

}
