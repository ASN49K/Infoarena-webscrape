#include <fstream>
#define nmax 1027
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[nmax],b[nmax],d[nmax][nmax],sol[nmax],k;

int main()
{   fin>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
       for(j=1;j<=m;++j)
          if(a[i]==b[j])
             d[i][j]=1+d[i-1][j-1];
         else d[i][j]=max(d[i-1][j],d[i][j-1]);

    i=n; j=m;
    while(i!=0 && j!=0)
        if(a[i]==b[j])
    { sol[++k]=a[i];
        i--;
        j--;
    }
    else if(d[i-1][j]<d[i][j-1])
        j--;
        else i--;
    fout<<k<<"\n";
      for(i=k;i>=1;i--)
        fout<<sol[i]<<" ";
    return 0;
}
