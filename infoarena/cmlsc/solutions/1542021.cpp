#include <iostream>
#include <fstream>
using namespace std;
int n,m,a[1025],b[1025],v[1025],mat[1026][1026],i,j,maxim,x;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main()
{
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(j=1;j<=m;j++)
        in>>b[j];
    for (i=n;i>=1;i--)
    {
        for(j=m;j>=1;j--)
        {
            if (a[i]==b[j])
                mat[i][j]=mat[i+1][j+1]+1;
            else
            {
                if(mat[i+1][j]>mat[i][j+1])
                    maxim=mat[i+1][j];
                else
                    maxim=mat[i][j+1];
                mat[i][j]=maxim;
            }
        }
    }
    out<<mat[1][1]<<endl;
    x=mat[1][1];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(mat[i][j]==x&&x-1==mat[i+1][j+1]&&x-1==mat[i+1][j]&&x-1==mat[i][j+1])
            {
                out<<a[i]<<" ";
                x--;
            }
        }
    }
}
