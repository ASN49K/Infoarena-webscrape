#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1050],b[1050],i,j,v[1050][1050],c[1050],l;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i=i+1)
    {
        fin>>a[i];
    }
    for(i=1;i<=m;i=i+1)
    {
        fin>>b[i];
    }
    for(i=1;i<=n;i=i+1)
    {
        for(j=1;j<=m;j=j+1)
        {
            if(a[i]==b[j])
            {
                v[i][j]=v[i-1][j-1]+1;
            }
            else
            {
                v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
        }
    }
    fout<<v[n][m]<<"\n";
    l=1;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            c[l]=a[i];
            l=l+1;
            i=i-1;
            j=j-1;
        }
        else
        {
            if(v[i-1][j]<v[i][j-1])
            {
                j=j-1;
            }
            else
            {
                i=i-1;
            }
        }
    }
    for(i=l-1;i>1;i=i-1)
    {
        fout<<c[i]<<" ";
    }
    fin.close();
    fout.close();
    return 0;
}
