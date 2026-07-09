#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int ma[12000][12000],a[1200],b[1200],n,m,i,j,nr,k,l,p,r,gasit,ok,c[1200],maxim,v=1;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
        k=1;
        l=1;
    for(i=1;i<=m;i++)
    {
        k++;
        ma[1][k]=b[i];

    }
    for(i=1;i<=n;i++)
    {
         l++;
        ma[l][1]=a[i];

    }
    nr=1;
    for(j=2;j<=m+1;j++)
    {

        {
        gasit=0;
        for(i=2;i<=n+1;i++)
        {
            if(gasit==0)
            {
            if(ma[i][1]==ma[1][j])
                {
                ma[i][j]=nr;
                nr++;
                gasit=1;
                }

                }
            }
        }
    }
    maxim=0;
   for(j=1;j<=m+1;j++)
    {
        for(i=1;i<=n+1;i++)
        {
        if(ma[i][j]>maxim);
            {
            maxim=ma[i][j];
            c[v]=ma[i][j];
            v++;
            }
        }
    }
    fout<<maxim<<endl;
    for(i=1;i<=v;i++)
        fout<<c[i]<<" ";
        return 0;
}
