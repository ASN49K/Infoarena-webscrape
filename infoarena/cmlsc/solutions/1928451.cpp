#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int mat[1025][1025],v[1025],b[1025],n,m;
void afisare(int i,int j)
{
    if(mat[i][j]!=0)
    {
        while(j>=1&&mat[i][j-1]==mat[i][j])
        {
            j--;
            cout<<"* ";
        }
         while(i>=1&&mat[i-1][j]==mat[i][j])
        {
            i--;
            cout<<"* ";
        }
        afisare(i-1,j-1);
        fout<<v[i]<<' ';
    }
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>v[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v[i]==b[j])
            {
                mat[i][j]=mat[i-1][j-1]+1;
            }
            else
                mat[i][j]=mat[i-1][j]>mat[i][j-1]?mat[i-1][j]:mat[i][j-1];
        }
    }
    fout<<mat[n][m]<<'\n';
    afisare(n,m);
    fout<<'\n';
    return 0;
}
