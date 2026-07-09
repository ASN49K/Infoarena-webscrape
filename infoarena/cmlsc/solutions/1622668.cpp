#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int A[102][102],B[1025],C[1025];
void afisare(int n,int m)
{
    if(m!=0&&n!=0)
    {
        if(B[n]==C[m])
        {
            afisare(n-1,m-1);
            fout<<B[n]<<" ";
        }
        else
            if(A[n-1][m]>A[n][m-1])
                afisare(n-1,m);
            else
                afisare(n,m-1);
    }
}
int main()
{
    int i,j,m,n;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>B[i];
    for(i=1;i<=m;i++)
        fin>>C[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(B[i]==C[j])
            {
                A[i][j]=A[i-1][j-1]+1;
            }
            else
                if(A[i-1][j]>A[i][j-1])
                    A[i][j]=A[i-1][j];
                else
                    A[i][j]=A[i][j-1];
        }
    fout<<A[n][m]<<"\n";
    afisare(n,m);
    return 0;
}
