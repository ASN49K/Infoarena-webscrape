#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n, m, x, maxi;
int v1[1025];
int v2[1025];
int dp1[1025];
int dp2[1025];
int main()
{
    in >> n >> m;

    for(int i = 1; i <= n; ++ i)
        in >> v1[i];

    for(int i = 1; i <= m; ++ i)
        in >> v2[i];

    if(n < m)
    {
        for(int i = 1; i <= n; ++ i)
            for(int j = 1; j <= m; ++ j)
                if(v1[i] == v2[j])
                {
                    ++ x;
                    dp1[j] = x;
                }
    }
    else
    {
        for(int i = 1; i <= m; ++ i)
            for(int j = 1; j <= n; ++ j)
                if(v1[j] == v2[i])
                {
                    ++ x;
                    dp1[j] = x;
                }
    }

    if(n < m)
    {
        swap(n, m);
        for(int i = 1; i <= m; ++ i)
            swap(v1[i], v2[i]);
    }

    for(int i = 1; i <= n; ++ i)
    {
        maxi = 0;
        for(int j = 1; j < i; ++ j)
            if(dp1[j] < dp1[i] && dp2[j] > maxi)
                maxi = dp2[j];
        if(dp1[i])
            dp2[i] = maxi + 1;
    }

    x = 1;
    for(int i = 1; i <= n; ++ i)
    {
        if(dp2[i] == x)
        {
            ++ x;
            out << v1[i] << " ";
        }
    }
    return 0;
}
