#include <iostream>
#include<fstream>
using namespace std;

int a[1025],b[1025],v[1025][1025],sir[1025];

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n,m,c=0;
    int i,j;
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(i=1; i<=m; i++)
        f>>b[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else if(v[i-1][j]>v[i][j-1])
                v[i][j]=v[i-1][j];
            else
                v[i][j]=v[i][j-1];
    i=n;
    j=m;
    while(i>0)
        if(a[i]==b[j])
        {

            sir[c]=a[i];
            c++;
            i--;
            j--;
        }
        else if(v[i-1][j]>v[i][j-1])
            i--;
        else
            j--;
    g<<v[n][m]<<endl;
    for (i=c-1; i>=0; i--)
    {
        g<<sir[i]<<' ';
    }
    return 0;
}
