#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short m,n,i,j,a[1025],b[1025],c[1025][1025],v[1025];

int main()
{
    fin>>m>>n;
    for(i=1;i<=m;++i)
        fin>>a[i];
    for(j=1;j<=n;++j)
        fin>>b[j];
    for(i=1;i<=m;++i)
        for(j=1;j<=n;++j)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
    i=c[m][n];
    j=i;
    fout<<i<<"\n";
    while(i)
    {
        if(a[m]==b[n])
        {
            v[i]=a[m];
            --m;
            --n;
            --i;
        }
        else
            if(c[m][n]==c[m-1][n])
                --m;
            else
                --n;
    }
    for(i=1;i<=j;++i)
        fout<<v[i]<<" ";
}
