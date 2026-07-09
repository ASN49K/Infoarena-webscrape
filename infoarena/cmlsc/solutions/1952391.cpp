#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short d[1030][1030], a[1030], b[1030], N, M, i, j, sir[1030], k;
int main()
{
    fin>>M>>N;
    for(i = 1; i <= M; ++i)
    {
        fin>>a[i];
    }
    for(i = 1; i <= N; ++i)
    {
        fin>>b[i];
    }
    for(i = 1; i <= M; ++i)
    {
        for(j = 1; j <= N; ++j)
        {
            if(a[i] == b[j])
            {
                if(d[i - 1][j] > d[i][j - 1])
                {
                    d[i][j] = d[i - 1][j] + 1;
                }
                else
                {
                    d[i][j] = d[i][j - 1] + 1;
                }
            }
            else if(d[i - 1][j] > d[i][j - 1])
            {
                d[i][j] = d[i - 1][j];
            }
            else
            {
                d[i][j] = d[i][j - 1];
            }
        }
    }
    fout<<d[M][N]<<'\n';
    i = M;
    j = N;
    k = 0;
    while(i)
    {
        if(a[i] == b[j])
        {
            sir[++k] = a[i];
        }
        if(d[i - 1][j] < d[i][j - 1])
        {
            --j;
        }
        else if(d[i - 1][j] > d[i][j - 1])
        {
            --i;
        }
        else
        {
            --j;
        }
    }
    for(i = k; i > 0; --i)
    {
        fout<<sir[i]<<" ";
    }
    return 0;
}
