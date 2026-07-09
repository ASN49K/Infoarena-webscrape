#include <iostream>
#include <fstream>
using namespace std;

#define MAX(a,b) (a>b ? a : b)
#define NMmax 1050

int m,n,a[NMmax],b[NMmax],c[NMmax][NMmax],sir[NMmax],bst;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    f>>m>>n;
    for(int i=1; i<=m; i++)
    {
        f>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        f>>b[i];
    }
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
        {
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=MAX(c[i-1][j],c[i][j-1]);
        }
    int i,j;
    for(int i=m; i>=1;)
        for(int j=n; j>=1;)
            if(a[i]==b[j])
                sir[++bst] = a[i], --i, --j;
            else if (c[i-1][j] < c[i][j-1])
                --j;
            else
                --i;
    g<<bst<<endl;
    for(i=bst; i>=1; i--)
        g<<sir[i]<<" ";
    g<<endl;
//    for(int i=1; i<=MAX(m,n); i++)
//    {
//        for(int j=1; j<=MAX(m,n); j++)
//            cout<<c[i][j]<<" ";
//        cout<<endl;
//    }
}
