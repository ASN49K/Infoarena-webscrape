#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025][1025],n,m;
void rsp(int i,int j){
    if(i==1 && j==1)
        return;
    if(a[i-1][j-1]==a[i][j]-1)
    {
        rsp(i-1,j-1);
        fout<<a[i][0]<<" ";
        return;
    }
    if(i==1 && j!=1 && a[i][j-1]==a[i][j]-1)
    {
        rsp(i,j-1);
        fout<<a[i][0]<<" ";
        return;
    }
    if(i!=1 && j==1 && a[i-1][j]==a[i][j]-1)
    {
        rsp(i-1,j);
        fout<<a[i][0]<<" ";
        return;
    }
    if(a[i-1][j]==a[i][j])
    {
        rsp(i-1,j);
        return;
    }
    if(a[i][j-1]==a[i][j])
    {
        rsp(i,j-1);
        return;
    }
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[0][i];
    for(int i=1;i<=m;i++)
        fin>>a[i][0];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            if(a[i][0]==a[0][j])
            {
                if(i!=1 && j!=1)
                    a[i][j]=a[i-1][j-1]+1;
                else if(i==1 && j!=1)
                    a[i][j]=a[i][j-1]+1;
                else if(i!=1 && j==1)
                    a[i][j]=a[i-1][j]+1;
            }
            else
            {
                 if(i!=1 && j!=1)
                    a[i][j]=max(a[i-1][j],a[i][j-1]);
                else if(i==1 && j!=1)
                    a[i][j]=a[i][j-1];
                else if(i!=1 && j==1)
                    a[i][j]=a[i-1][j];

            }

        }

    fout<<a[m][n];
    fout<<endl;
    rsp(m,n);
    return 0;
}
