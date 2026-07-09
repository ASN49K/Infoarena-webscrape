#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],re[1025],ma[1025][1025];
int main()
{
    int n,m,i,j,k;
    f>>n>>m;
    for(i = 1; i <= n; i++)
        f>>a[i];
    for(i = 1; i <= m; i++)
        f>>b[i];

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
    {
        if(a[i] == b[j])
            ma[i][j] = ma[i-1][j-1] +1;
        else
            ma[i][j] = max(ma[i-1][j] , ma[i][j-1]);
    }
    g<<ma[n][m]<<"\n";
    k=ma[n][m];
   i=n;
   j=m;
    while(ma[i][j])
    {
        while(ma[i][j] == ma[i-1][j])
            i--;
        while(ma[i][j] == ma[i][j-1])
            j--;
            re[k]=a[i];
            k--;
            j--;
            i--;
    }
    for(i = 1; i <= ma[n][m]; i++)
        g<<re[i]<<" ";

    return 0;
}
