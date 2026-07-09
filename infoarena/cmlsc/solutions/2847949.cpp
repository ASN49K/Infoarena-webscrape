#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


#define MAXN 1026

int a[MAXN], b[MAXN], d[MAXN][MAXN], rez[MAXN];
int main()
{

    int n, m, i, j;

    fin >> n >> m;

    for(i = 1; i <= n; i++)
        fin >> a[i];
    for(i = 1; i <= m; i++)
        fin >> b[i];


    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }


    i = n;
    j = m;
    int dim = 0;
    while(i > 0 && j > 0)
    {
        if(a[i] == b[j])
        {
            rez[++dim] = a[i];
            i--;
            j--;
        }
        else if(d[i - 1][j] < d[i][j - 1])
           j--;
        else
           i--;
    }

    fout << d[n][m] <<  endl;
    for(i = dim; i > 0; i --)
        fout << rez[i] << " ";


    return 0;
}
