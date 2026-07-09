#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 1024
using namespace std;

int n,m;
char s1[NMAX+1],s2[NMAX+1];
int mat[NMAX+1][NMAX+1];

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");



void afis()
{
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            fout<<mat[i][j]<<" ";
        }
        fout<<"\n";
    }
}

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        int x;
        fin>>x;
        s1[i]=x;
    }
    for(int i=1; i<=m; i++)
    {
        int x;
        fin>>x;
        s2[i]=x;
    }

    //incep sa imi formez matricea
    //incep cu sirul 2
    //sirul 2 e pus |
    //sirul 1 e -
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s2[i]==s1[j])
            {
                mat[i][j]=mat[i][j-1]+1;
            }
            else
            {
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
    //afis();
    int k=0;
    char sol[NMAX+1];
    int lin=m,col=n;
    while(lin>=1 && col>=1)
    {
        if(mat[lin][col]==0)
        {
            break;
        }
        while(mat[lin][col]==mat[lin-1][col])
        {
            lin--;
        }
        while(mat[lin][col]==mat[lin][col-1])
        {
            col--;
        }
        if(mat[lin-1][col]==mat[lin][col-1])
        {
            //sunt la coltul unui dreptunghi
            k++;
            sol[k]=s1[col];
            lin--;
            col--;
        }
    }
    fout<<k<<"\n";
    for(int i=k; i>=1; i--)
    {
        fout<<(int)sol[i]<<" ";
    }
    return 0;
}
