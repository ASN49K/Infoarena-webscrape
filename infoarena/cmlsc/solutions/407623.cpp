#include<fstream>
using namespace std;
#define dim 1024
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[dim],b[dim],lcs[dim+1][dim+1],m,n;
void pd()
{
    for(int k=1;k<=n;k++)
        for(int h=1;h<=m;h++)
            if(a[k]==b[h])
                lcs[k-1][h]=1+lcs[k-1][h-1];
            else
            if(lcs[k-1][h]>lcs[k][h-1])
                lcs[k][h]=lcs[k-1][h];
                else
                lcs[k][h]=lcs[k][h-1];
}
void print()
{
    g<<lcs[n][m];
    int d[dim],p;
    for(int i=0,k=n,h=m;lcs[k][h];)
           {
               if(a[k]==b[h])
                {
                d[i++]=a[k];k--;h--;p=i;
                }
                else
                if(lcs[k][h]==lcs[k-1][h])
                k--;
                else
                h--;

           }
    for(p;p>=0;p--) g<<d[p]<<' ';
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
