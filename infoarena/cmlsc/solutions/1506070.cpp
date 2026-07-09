#include <fstream>
#include <cstdio>
#include <vector>
//#include <math.h>

#define dmax 1025
using namespace std;
int a[dmax],b[dmax],c[dmax][dmax],n,m,i,j;
vector <int> v;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    f>>n>>m;

    for(i=1;i<=n;i++)
        f >> a[i];
    for(i=1;i<=m;i++)
        f >> b[i];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
        }

/**
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            g<<c[i][j]<<" ";
        }
        g<<"\n";
    }

*/
    g << c[n][m] << endl;
    for( i=n,j=m; c[i][j]; )
        {
            if(a[i]==b[j]){ v.push_back(a[i]); i--; j--; }
            else if(c[i-1][j]>=c[i][j-1]) i--;
            else j--;
        }
    for(vector <int>::reverse_iterator it=v.rbegin();it!=v.rend();it++) g << *it<<" ";
    return 0;
}
