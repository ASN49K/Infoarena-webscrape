#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],v[1025],b[1025],c[1025][1025],st[1025];
int main()
{
   int n,m,i,j,mx,k=0;
   fin>>n>>m;
   for(i=1;i<=n;i++)
   {
    fin>>v[i];
   }
   for(j=1;j<=n;j++)
   {
       fin>>b[j];
   }for(i=1;i<=n;i++)
{
    for(j=1;j<=m;j++)
    {
        if(v[i]==b[j])c[i][j]=1+c[i-1][j-1];
        else c[i][j]=max(c[i-1][j],c[i][j-1]);
    }
}
mx=c[n][m];
fout<<mx<<"\n";
 mx=c[n][m];
    i=n;
    j=m;

    while(mx)
    {
        if(v[i]==b[j])
        {
            k++;
            st[k]=v[i];
            mx--;
            i--;
            j--;
        }
        else if(mx==c[i-1][j]) i--;
        else j--;
    }
    for(i=k;i>=1;i--)
    {
        fout<<st[i]<<" ";
    }

    return 0;
}
