#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int C[1025][1025],A[1025],B[1025],n,m;

void citire()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>A[i];
    for(int i=1;i<=m;i++)
        fin>>B[i];
}

void afisare(int i,int j)
{
    if(i>0&&j>0)
    {
        if(A[i]==B[j])
        {
            afisare(i-1,j-1);
            fout<<A[i]<<" ";
        }
        else
        {
        if(C[i][j-1]>C[i-1][j])

            afisare(i,j-1);
        else
            afisare(i-1,j);
        }
    }

}

int main()
{
    int i,j;
    citire();
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(A[i]==B[j])
                C[i][j]=C[i-1][j-1]+1;
            else
                C[i][j]=max(C[i][j-1],C[i-1][j]);
    fout<<C[n][m]<<'\n';
    afisare(n,m);
    return 0;
}
