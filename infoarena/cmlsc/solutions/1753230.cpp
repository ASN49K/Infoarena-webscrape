

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
ofstream out("cmlsc.out");
#define dim 1030

int x1[dim], x2[dim], sol[dim][dim], n , m;

vector < int > S;

void Read();
void Solve();
int main()
{
    Read();
    Solve();

    out << sol[n][m] << '\n';

    int i,j;
    for(i=n,j=m;i;)
    {
        if(x1[i] == x2[j])
        {
            S.push_back(x1[i]);
            --i;
            --j;
        }
        else
        if(sol[i-1][j] < sol[i][j-1])
        {
            --j;
        }
        else
        {
            --i;
        }
    }

    reverse(S.begin(),S.end());

    for(vector <int>:: iterator I = S.begin(); I!= S.end(); ++I)
        out << *I << " ";

    return 0;
}

void Read()
{
    ifstream in("cmlsc.in");

    in >> n >> m;

    for(int i = 1; i<=n; ++i)
    {
        in >> x1[i];
    }

    for(int i = 1 ; i<=m; ++i)
    {
        in >> x2[i];
    }

    for(int i = 1 ; i<=n; ++i)
    {
        sol[i][0] = 0;
    }

    for(int i = 1 ; i<=m; ++i)
    {
        sol[0][i] = 0;
    }
}

void Solve()
{
    for(int i = 1; i<=n; ++i)
    {
        for(int j = 1 ; j<=m; ++j)
        {
            if(x1[i] == x2[j])
            {
                sol[i][j] = sol[i-1][j-1] + 1;
            }
            else
            {
                sol[i][j] = max(sol[i-1][j],sol[i][j-1]);
            }
        }
    }
}
