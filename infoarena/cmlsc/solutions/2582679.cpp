#include <fstream>
#include <vector>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
vector<int>rez;
int a[1030],b[1030],mat[1030][1030],n,m,i,j;
int main()
{
    in>>m>>n;
    for(i=1;i<=m;i++)
    {
        in>>a[i];
    }
    for(j=1;j<=n;j++)
    {
        in>>b[j];
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else if(mat[i][j-1]<=mat[i-1][j])
                mat[i][j]=mat[i-1][j];
            else if(mat[i-1][j]<mat[i][j-1])
                mat[i][j]=mat[i][j-1];
        }
    }
    i=m;
    j=n;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            rez.push_back(a[i]);
            i--;
            j--;
        }
        else if(mat[i][j-1]>=mat[i-1][j])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    out<<mat[m][n]<<'\n';
    for(i=rez.size()-1;i>=0;i--)
        out<<rez[i]<<' ';
    out<<'\n';
    return 0;
}
