#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,a[1500],b[1500],v[1500][1500],sir[1500],i,j,k;

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
            {
                if(v[i-1][j]>v[i][j-1])
                    v[i][j]=v[i-1][j];
                else
                    v[i][j]=v[i][j-1];
            }
        }
    }
    fout<<v[n][m]<<"\n";
  //  for(i=1;i<=n;i++)
   // {
  //      for(j=1;j<=m;j++)
  //      fout<<v[i][j];
  //      fout<<"\n";
   // }
    i=n;j=m;
    k=0;
    while(v[i][j])
    {
        if(a[i]==b[j])
        {
            k++;
            sir[k]=a[i];
            i--;
            j--;
        }
        else
        {
            if(v[i][j-1]<v[i-1][j])
                i--;
            else
                j--;
        }
    }
    for(i=k;i>0;i--)
        fout<<sir[i]<<" ";
    return 0;
}
