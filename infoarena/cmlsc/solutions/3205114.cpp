#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[2000],b[2000],d[2000][2001],val[2001],k;


int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int j=1;j<=m;j++)
        fin>>b[j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {


            if(a[i]==b[j])
            {
                d[i][j]=1+d[i-1][j-1];




            }
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }



    }
    int l=n,c=m;
   while(l>0 && c>0)
   {

       if(a[l]==b[c])
       {
           val[++k]=a[l];
           l--;
           c--;
       }
       else if(d[l-1][c]<d[l][c-1])
        c--;
       else
        l--;
   }
   fout<<k<<"\n";
   for(int i=k;i>=1;i--)
    fout<<val[i]<<" ";


    return 0;
}
