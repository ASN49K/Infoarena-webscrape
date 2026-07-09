#include<fstream>
using namespace std;
int  i,j,k,n,m,a[1026],b[1026],c[1026][1026],x[1026],p,ok;
//fstream fin,fout;
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>m>>n;
    for(i=1;i<=m;i++)
    {
        fin>>a[i];
    }
    for(j=1;j<=n;j++)
    {
        fin>>b[j];
    }
    for(i=0;i<=m;i++)
    {
        c[i][0]=0;
    }
    for(j=0;j<=n;j++)
    {
        c[0][j]=0;
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                c[i][j]=1+c[i-1][j-1];
            }
            else
            {
                if(c[i][j-1]>c[i-1][j])
                   {
                       c[i][j]=c[i][j-1];
                   }
                   else
                   {
                       c[i][j]=c[i-1][j];
                   }
            }
        }
    }
    i=m;
    j=n;
    for(p=c[m][n];p>=1;p--)
    {
        ok=0;
        while(ok==0)
        {
            for(k=1;k<=j;k++)
            {
                if(c[i][k]==p && a[i]==b[k])
                {
                    x[p]=a[i];
                    i=i-1;
                    j=k-1;
                    ok=1;
                    break;
                }
            }
            if(ok==0)
            {
                for(k=1;k<=i;k++)
                {
                    if(c[k][j]==p && a[k]==b[j])
                    {
                        x[p]=a[k];
                        i=k-1;
                        j=j-1;
                        ok=1;
                    }
                }
            }
            if (ok==0)
            {
                i--;
                j--;
            }
        }
    }
    fout<<c[m][n]<<"\n";
    for(i=1;i<=c[m][n];i++)
    {
        fout<<x[i]<<" ";
    }
    fin.close();
    fout.close();
    return 0;
}
