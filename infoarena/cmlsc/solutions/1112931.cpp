#include <fstream>
#include <algorithm>
using namespace std;
FILE*fin;
ofstream fout("cmlsc.out");
int a[1025],b[1025],i,j,n,m,sol[1025],d[1025][1025],k;
int main()
{
    fin=fopen("cmlsc.in","r");
    fscanf(fin,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
        fscanf(fin,"%d",&a[i]);
    for(j=1;j<=m;j++)
        fscanf (fin,"%d",&b[j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
    i=n;
    j=m;
    while(i)
    {
        if(a[i]==b[j])
        {
            k++;
            sol[k]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else i--;
    }
    fout<<k<<'\n';
    for(i=k;i>=1;i--)
        fout<<sol[i]<<" ";
    return 0;
}
