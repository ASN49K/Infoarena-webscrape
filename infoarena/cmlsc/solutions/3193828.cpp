#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
long long int a[1024][1024];
int main()
{
    long long int n,m,v1[1024],v2[1024],vc[1024],i,j,k;
    fin>>n>>m;
    for(i=1;i<=n;i++)fin>>v1[i];
    for(i=1;i<=m;i++)fin>>v2[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
            {
                a[i][j]=a[i-1][j-1]+1;
            }
            else
            {
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    i=n;j=m;k=0;
    while(i>0 && j>0)
    {
        if(v1[i]==v2[j])
        {
            k++;
            vc[k]=v1[i];
            i--;j--;
        }
        else
        {
            if(a[i-1][j]>=a[i][j-1])
            {
                i--;
            }
            else j--;

        }
    }
    fout<<k<<endl;
    for(i=k;i>=1;i--)
    {
        fout<<vc[i]<<" ";
    }


    return 0;
}
