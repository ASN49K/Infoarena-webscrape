#include <bits/stdc++.h>
#define Nmax 1050

using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int a[Nmax],b[Nmax],c[Nmax][Nmax],i,j,n,m;

inline void read()
{
    f >> n >> m;
    for(i = 1;i <= n;i++)
        f >> a[i];

    for(i = 1;i <= m;i++)
        f >> b[i];
}

inline void dinamic()
{
    for(i = 1;i <= n;i++)
        for(j = 1;j <= m;j++)
            if(a[i] == b[j])
               c[i][j] = c[i - 1][j - 1] + 1;
            else c[i][j] = max(c[i - 1][j], c[i][j - 1]);

    g << c[n][m] << '\n';
}

inline void afisare(int i,int j)
{
    if(i == 0 || j == 0)
        return;
    if(a[i] == b[j])
    {
        afisare(i - 1,j - 1);
        g << a[i] << " ";
    } else if(c[i - 1][j] > c[i][j - 1])
        afisare(i - 1,j);
    else afisare(i,j - 1);
}

int main()
{
    read();
    dinamic();
    afisare(n,m);
    return 0;
}
