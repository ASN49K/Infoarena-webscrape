#include<fstream>
using namespace std;
#define dim 1025
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[dim],b[dim],lcs[dim+1][dim+1],m,n;
void pd()
{
    for(int k=1;k<=m;k++)
        for(int h=1;h<=n;h++)
            if(a[k]==b[h])
                lcs[k][h]=1+lcs[k-1][h-1];
            else
            if(lcs[k-1][h]>lcs[k][h-1])
                lcs[k][h]=lcs[k-1][h];
                else
                lcs[k][h]=lcs[k][h-1];
}
void print()
{
    g<<lcs[m][n]<<' ';
    int nr=0,sol[1025],i,j;
    for(i=m,j=n;i>=1;)
    {       if(a[i]==b[j])
       {         sol[++nr]=a[i];
           i--; j--;
      }
       else
           if(lcs[i-1][j]<lcs[i][j-1])
               j--;
           else
                i--;
    }
    for(i=nr;i>=1;i--)
        g<<sol[i]<<" ";
    g.close();
}

int main()
{
    f>>m>>n;
    for(int i=1;i<=m;i++)
        f>>a[i];
    for(int j=1;j<=n;j++)
        f>>b[j];
    pd();
    print();
    f.close();
    g.close();
    return 0;
}
