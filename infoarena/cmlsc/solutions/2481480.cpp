#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int b[1030], a[1030];
int sol[1030][1030];
int n, G, Max, m, cnt;
int main()
{
    in >> n >> m;
    for(int i = 1;i <= n;i++)
        in >> a[i];
    for(int i = 1;i <= m;i++)
        in >> b[i];
    for(int i = 1;i <= n;i++)
    {
        bool OK = 1;
        for(int j = 1;j <= m && OK;j++)
            if(a[i] == b[j])
            {
                if(sol[i][j] == 0 && OK)
                {
                    sol[i][j] = a[i];
                    cnt++;
                    OK = 1;
                }
            }
    }
    out << cnt << '\n';
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            if(sol[i][j] == a[i]) out << a[i] << " ";
    return 0;
}
