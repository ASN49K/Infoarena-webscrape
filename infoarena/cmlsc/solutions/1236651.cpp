#include<fstream>
#define NMAX 1025

using namespace std;

short int n,m, a[NMAX], b[NMAX], d[NMAX][NMAX], sir[NMAX], index=0;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    f>>n>>m;
    for(int i=1;i<n+1;i++)
        f>>a[i];
    for(int i=1;i<m+1;i++)
        f>>b[i];

    for(int i=1;i<n+1;i++)
        for(int j=1;j<m+1;j++)
        {
           if(a[i]==b[j])
              d[i][j]=1+d[i-1][j-1];
           else
              d[i][j]=max(d[i][j-1],d[i-1][j]);
        }

    for(int i=n, j=m; i!=0; )
    {
        if(a[i]==b[j])
        { sir[index++] =  a[i];i--;j--;}
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else
            i--;
    }

    g<<index<<'\n';
    for(int i=index-1;i>=0;i--)
        g<<sir[i]<<' ';

    f.close();g.close();
    return 0;
}
