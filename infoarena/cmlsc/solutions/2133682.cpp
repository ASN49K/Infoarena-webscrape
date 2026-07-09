#include <iostream>
#include <fstream>
#define NMAX 1030
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int n, m;
int a[NMAX];
int b[NMAX];
short int lgmax[NMAX][NMAX];
short int unde[NMAX][NMAX];
void citire();
void afis();
int main()
{
    int i, j;
    citire();
    //dinamica
    for (i=n; i>0; i--)
        for (j=m; j>0; j--)
            if (a[i]==b[j])
            {
                lgmax[i][j]=1+lgmax[i+1][j+1];
                unde[i][j]=1;
            }
            else
            {
                if(lgmax[1+i][j]>lgmax[i][j+1])
                {
                    lgmax[i][j]=lgmax[1+i][j];
                    unde[i][j]=2;
                }
                else
                {
                    lgmax[i][j]=lgmax[i][j+1];
                    unde[i][j]=3;
                }
            }
    afis();
    return 0;
}
void afis ()
{
    fout<<lgmax[1][1]<<'\n';
    int i=1; int j=1;
    while (i<=n&&j<=m)
    {
        if (unde[i][j]==1)
        {
            fout<<a[i]<<' ';
            i++; j++;
        }
        else if (unde[i][j]==2)
            i++;
        else
            j++;
    }
    fout<<'\n';
    fout.close();
}
void citire()
{
    int i, j;
    fin>>n>>m;
    for (i=1; i<=n; i++)
        fin>>a[i];
    for (j=1; j<=m; j++)
        fin>>b[j];
}
