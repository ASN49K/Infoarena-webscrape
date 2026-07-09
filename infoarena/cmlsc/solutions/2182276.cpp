#include <iostream>
#include <fstream>

#define max_len 1024

using namespace std;
int a[max_len][max_len] = {0};
    int x[max_len], y[max_len], sir[max_len];
    int n, m, k;
    int i, j;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");




    f >> n >> m;

    for (i = 1; i <= n; i++)
        f >> x[i];

    for (i = 1; i <= m; i++)
        f >> y[i];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (x[i] == y[j])
                a[i][j] = 1 + a[i-1][j-1];
            else
                a[i][j] = max(a[i-1][j], a[i][j-1]);

    k = 0;
    i=n;
    j=m;
    while(i>=1&&j>=1)
    {
        while(a[i][j]==a[i-1][j])
        {
            i--;
        }
        while(a[i][j]==a[i][j-1])
        {
            j--;
        }
        if(x[i]==y[j])
        {
            k++;
            sir[k]=x[i];
        }
        i--;
        j--;
    }
    g<<k<<"\n";
    for (i = k; i >= 1; i--)
        g << sir[i] <<" ";

    return 0;
}
