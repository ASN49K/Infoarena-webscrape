#include <iostream>
#include <fstream>

using namespace std;

int v1[1030], v2[1030];
int n1, n2, k;
int d[1030][1030];
int sol[1030];

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void lev()
{
    for(int i = 1; i <= n1; ++ i)
        for(int j = 1; j <= n2; ++ j)
            if(v1[i] == v2[j])    d[i][j] = d[i - 1][j - 1] + 1;
            else                  d[i][j] = max(d[i - 1][j], d[i][j - 1]);
}

int main()
{
    in >> n1 >> n2;
    for(int i = 1; i <= n1; ++ i) in >> v1[i];
    for(int i = 1; i <= n2; ++ i) in >> v2[i];

    lev();

    out << d[n1][n2] << '\n';

    int i = n1;
    int j = n2;
    while(i && j)
    {
        if(d[i - 1][j - 1] == d[i][j] - 1)
        {
            sol[++ k] = v1[i];
            -- i;
            -- j;
        }
        else
            if(d[i - 1][j] == d[i][j]) -- i;
            else -- j;
    }

    for(int i = k; i > 0; -- i) out << sol[i] << " ";
    return 0;
}
