#include <fstream>
using namespace std;
#define MAX 1024

unsigned int a[MAX],b[MAX],c[MAX],final[MAX],n,m,f,i,j;

int main() {
    ifstream f("cmlsc.in",ifstream::in);
    ofstream g("cmlsc.out",ifstream::out);
    f>>m>>n;
    for (i=1;i<=m;i++)
        f>>a[i];
    for (i=1;i<=n;i++)
        f>>b[i];
    for (i=1;i<=m;i++)
         for (j=1;j<=n;j++)
             if (a[i]==b[j])
                c[i][j]=1+c[i-1][j-1];
             else
                if (c[i-1][j]<c[i][j-1])
                   c[i][j]=c[i][j-1];
                else
                    c[i][j]=c[i-1][j];
     i=m;j=n;
     while (i && j)
           if (a[i]==b[j]) {
                           final[f++]=a[i];
                           i--;
                           j--;
                           }
           else
               if (c[i][j-1]>c[i-1][j])
                  j--;
               else
                   i--;
     g<<f<<'\n';
    for (i=f-1;i>=0;i--)
        g<<final[i]<<' ';
    return 0;
}
