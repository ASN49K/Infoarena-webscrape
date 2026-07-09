#include <fstream>
#include <iostream>
#define nmax 1025
#define maxim(a,b) (a>b? a:b)
using namespace std;
int m,n,i,j,bst,a[nmax],b[nmax],d[nmax][nmax],sir[nmax];
int main()
{
    ifstream f;
    f.open("cmlsc.in");
    f>>m>>n;
    for (i=1;i<=m;i++) f>>a[i];
    for (i=1;i<=n;i++) f>>b[i];
    f.close();
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            if (a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
            else d[i][j]=maxim(d[i-1][j],d[i][j-1]);
    i=m;
    j=n;
    while (i>0 && j>0)
    {
        if (a[i]==b[j])
        {
            sir[++bst]=a[i];
            i--;
            j--;
        }
        else if (d[i][j-1]>d[i-1][j]) j--;
                                else i--;
    }
    ofstream g;
    g.open("cmlsc.out");
    g<<bst<<"\n";
    for (i=bst;i>0;i--) g<<sir[i]<<" ";
    g.close();
    return 0;

}
