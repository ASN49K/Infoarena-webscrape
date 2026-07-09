#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int mat[1025][1025], m, n, i, j, maxim, a[1025], b[1025], c[1025], l1, l2;
int main()
{
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(i=1; i<=m; i++)
        fin>>b[i];

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
            {
                maxim=mat[i-1][j];
                if(maxim<mat[i-1][j-1])
                    {maxim=mat[i-1][j-1];}
                if(maxim<mat[i][j-1])
                    {maxim=mat[i][j-1];}
                mat[i][j]=maxim;
            }
        }
    fout<<mat[n][m]<<"\n";

    int k=0;

    i=n; j=m;
    while(mat[i][j]!=0)
    {
        if(a[i]==b[j])
        {
            c[++k]=a[i];
            i--;
            j--;
        }
        else
        {
            maxim=mat[i-1][j];
            l1=i-1;
            l2=j;
            if(maxim<mat[i-1][j-1])
            {
                maxim=mat[i-1][j-1];
                l1=i-1;
                l2=j-1;
            }
            if(maxim<mat[i][j-1])
            {
                maxim=mat[i][j-1];
                l1=i;
                l2=j-1;
            }
            i=l1;
            j=l2;
        }
    }

    for(i=k; i>=1; i--)
        fout<<c[i]<<" ";

    return 0;
}
