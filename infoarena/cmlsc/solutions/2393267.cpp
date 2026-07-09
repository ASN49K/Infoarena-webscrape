#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int dim = 1026;

int n,m,a[dim],b[dim],d[dim][dim];

void Afisare(int i,int j)
{
    if (d[i][j] == 0)
    {
        return ;
    }
    if (a[i] == b[j])
    {
        Afisare(i-1,j-1);
        out << a[i] << " ";
    }
    else
    {
        int x = i-1,y = j;
        if (d[x][y] < d[i][j-1])
        {
            x = i;
            y = j-1;
        }
        Afisare(x,y);
    }
}

int main()
{
    int i,j;
    in >> n >> m;
    for (i=1; i<=n; i++)
    {
        in >> a[i];
    }
    for (i=1; i<=m; i++)
    {
        in >> b[i];
    }
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            if (a[i] == b[j])
            {
                d[i][j] = 1 + d[i-1][j-1];
            }
            else d[i][j] = max(d[i-1][j],d[i][j-1]);
        }
    }
    /*for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }*/
    out << d[n][m] << "\n";
    Afisare(n,m);
    return 0;
}
