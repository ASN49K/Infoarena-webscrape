#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,a[1025],b[1025],d[1025][1025],vec[1025],cate=0;
int main()
{
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];


    for(i=1; i<=m; i++)
        fin>>b[i];


    for(i=0; i<=n; i++)
        for(j=0; j<=m; j++)
        {
            if (i==0 or j==0)
            {
                d[i][j]=0;
            }
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }

    i=n;
    j=m;
    while(i and j)
    {
        if(a[i]==b[j])
        {
            vec[++cate]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else
            i--;
    }
    fout<<cate<<'\n';
    for(i=cate; i>=1; i--)
        fout<<vec[i]<<' ';
    return 0;
}
