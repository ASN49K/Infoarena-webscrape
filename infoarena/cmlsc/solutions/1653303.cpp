#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int b[1030],c[1030][1030],a[1030],x[1030],m,n,i,j,k;
char d[1030][1030];
int main()
{
    fin>>m>>n;
    for(i=1;i<=m;i++)
    {
        fin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        fin>>b[i];
    }
    for(i=1;i<=m;i++)
    for(j=1;j<=n;i++)
    {
        if(a[i]==b[j])
        {
            c[i][j]=1+c[i-1][j-1];
            d[i][j]='\\';
        }
        else
        {
           if(c[i-1][j]>c[i][j-1])
           {
               c[i][j]=c[i-1][j];
               d[i][j]='|';
           }
           else
           {
               c[i][j]=c[i][j-1];
               d[i][j]='-';
           }
        }
    }
    fout<<c[m][n]<<endl;
    i=m;
    j=n;
    k=0;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            k++;
            x[k]=a[i];
        }
        if(d[i][j]=='\\')
        {
            i--;
            j--;
        }
        else
        {
            if(d[i][j]=='|')
            {
                i--;
            }
            else
            {
                j--;
            d[i][j]='-';}

        }
    }
    for(i=k;i>=1;i--)
    {
        fout<<x[i]<<" ";
    }
    fout.close();
    fin.close();
    return 0;
}
