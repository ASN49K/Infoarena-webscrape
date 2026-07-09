#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int  ma[1026][1026];
int main()
{
    int n,m,a[1026],b[1026],i,j,c[1000];
    f >> n >> m;
    for(int i = 1 ; i <= n; i++)
        f >> a[i];
    for(int i = 1 ; i <= m; i++)
        f >> b[i];
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                ma[i][j] = ma[i-1][j-1] +1;
            else
                ma[i][j] = max(ma[i-1][j],ma[i][j-1]);
        }
    }
    i = n; j = m;
    int e = ma[i][j];
    g << e << "\n";
    while(e != 0)
    {
        while(ma[i][j] == ma[i-1][j])
            i--;
        while(ma[i][j] == ma[i][j-1])
            j--;
        c[e] = a[i];

        i--;
        j--;
        e--;
    }
    for(i = 1 ; i <= ma[n][m]; i++)
        g << c[i] << " ";

    return 0;
}
