#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1030], b[1030], n, m, sol[1030][1030];
stack<int> afis;

int main()
{
    fin>>n>>m;
    int i, j;

    for(i = 1; i <= n; ++i)
        fin>>a[i];
    for(i = 1; i <= m; ++i)
        fin>>b[i];

    for(i = 1; i <= n; ++i)
    {
        for(j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
                sol[i][j] = sol[i-1][j-1] + 1;
            else
                sol[i][j] = max(sol[i-1][j], sol[i][j-1]);
        }
    }

    fout<<sol[n][m]<<'\n';

    i = n, j = m;
    while(i >= 1 && j >= 1)
    {
        if(a[i] == b[j])
        {
            afis.push(a[i]);
            --i;
            --j;
        }
        else
        {
            if(sol[i-1][j] < sol[i][j-1])
                --j;
            else
                --i;
        }
    }

    while(!afis.empty())
    {
        fout<<afis.top()<<' ';
        afis.pop();
    }
    return 0;
}
