#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,vn[1025],vm[1025],l,mat[1025][1025],rez[1025];
/*int exec (int a,int b)
{
    if (a==0 || b==0)
        return 0;
    else if (vn[a]==vm[b])
    {

        return exec(a-1,b-1)+1;
    }
    else
    {
        return max(exec(a-1,b),exec(a,b-1));
    }
}*/
int main()
{
    f>>n>>m;
    for (int i=1; i<=n; i++)
    {
        f>>vn[i];
    }
    for (int i=1; i<=m; i++)
        f>>vm[i];
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (vn[i]==vm[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    }
    int i=n,j=m;
    while (i>=1 && j>=1)
    {
        if (vn[i]==vm[j])
        {
            l++;
            rez[l]=vn[i];
            i--;
            j--;
        }
        else
        {
            if (mat[i-1][j]>mat[i][j-1])
                i--;
            else j--;
        }
    }
    g<<l<<'\n';
    for (int i=l; i>=1; i--)
        g<<rez[i]<<' ';
    /*cout<<exec(n,m)<<'\n';
    for (int j=l; j>0; j--)
        cout<<rez[j]<<' ';*/
    return 0;
}
