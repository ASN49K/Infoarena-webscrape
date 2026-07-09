#include <iostream>
#include <fstream>
using namespace std;

#define maxim(a,b) ((a>b) ? a : b)
#define nr 5000

int m,n,a[nr],b[nr],c[nr][nr],bst,sir[nr];

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>m>>n;
    int i,j;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(i=1;i<=n;i++)
        f>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                c[i][j]=1+c[i-1][j-1];
            else
                c[i][j]=maxim(c[i-1][j],c[i][j-1]);
    i=m;
    j=n;
    while(i&&j)
    {

            if(a[i]==b[j])
            {
                sir[++bst]=a[i];
                --j;
                --i;
            }
            else
                if(c[i-1][j]<c[i][j-1])
                    --j;
                else
                    --i;
    }
    g<<bst<<endl;
    for(i=bst;i>=1;i--)
        g<<sir[i]<<" ";
}
