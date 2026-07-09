#include <fstream>
using namespace std;

unsigned char a[1025],b[1025],c[1025][1025],final[1025];
int n,m,fi,i,j;

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
                           final[fi++]=a[i];
                           i--;
                           j--;
                           }
           else
               if (c[i][j-1]>c[i-1][j])
                  j--;
               else
                   i--;
     g<<fi<<'\n';
    for (i=fi-1;i>=0;i--)
        g<<final[i]<<' ';
    return 0;
}
