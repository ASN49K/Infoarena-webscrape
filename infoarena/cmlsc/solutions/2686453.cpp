#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int a[1030] , b[1030];
int n , m;
int rr[1030][1030];
array <bitset<1030> , 1030 > f;
int rez[1030] , nr_rez;


int r(int i , int j)
{
    if (f[i][j] == 1)
        return rr[i][j];
    if (a[i] == b[j])
    {
        rr[i][j] = r(i-1 , j-1) + 1;
        rez[nr_rez] = a[i];
        nr_rez++;
    }
    else
    {
        rr[i][j] = max(r(i-1 , j) , r(i , j-1));
    }
    f[i][j] = 1;
    return rr[i][j];
}

int main()
{
    fin >> n >> m;
    for (int i=1;i<=n;i++)
        fin >> a[i];

    for (int j=1;j<=m;j++)
        fin >> b[j];

    for (int i=0;i<=max(n , m);i++)
    {
        f[0][i] = 1;
        f[i][0] = 1;
    }
    rr[n][m] = r(n , m);


    fout << rr[n][m] << '\n';
    for (int i=nr_rez-1;i>=0;i--)
        fout << rez[i] << ' ';

    return 0;
}
