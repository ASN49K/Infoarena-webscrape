#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,mat[1025][1025],a[1025],b[1025],rez[1025],k=0;
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
           if(a[j]==b[i])
            {
                mat[i][j]=mat[i-1][j-1]+1;
            }
           else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    fout<<mat[m][n]<<"\n";
    int i=m;
    int j=n;
    while(i>0 && j>0)
    {
        if(a[j]==b[i])
        {
            k++;
            rez[k]=a[j];
            i--;
            j--;
        }
        else if(mat[i-1][j]>mat[i][j-1])
                i--;
                else
                    j--;
    }
    while(k>0)
        {fout<<rez[k]<<" ";
        k--;
    }
    return 0;
}
