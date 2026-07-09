#include <fstream>

using namespace std;

int m, n, a[1025][1025], b[1025][1025], x[1025], y[1025], mx;

ifstream in("clmsc.in");
ofstream out("clmsc.out");

void read()
{
    in>>m>>n;
    for(int i = 1; i <= m; in>>x[i++]);
    for(int i = 1; i <= n; in>>y[i++]);
}

void lcs()
{
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(x[i] == y[j])
            {
                a[i][j] = a[i - 1][j - 1] + 1;
                b[i][j] = 1;
            }
            else if(a[i - 1][j] >= a[i][j - 1])
            {
                a[i][j] = a[i - 1][j];
                b[i][j] = 2;
            }
            else
            {
                a[i][j] = a[i][j - 1];
                b[i][j] = 3;
            }
        }
    }
}

void reconstruct(int i, int j)
{
    if(i > 0 && j > 0)
    {
        if(b[i][j] == 1)
        {
            reconstruct(i - 1, j - 1);
            out<<x[i]<<' ';
        }
        else if(b[i][j] == 2)
            reconstruct(i - 1, j);
        else
            reconstruct(i, j - 1);
    }
}

void print()
{
    out<<a[m][n]<<'\n';
    reconstruct(m, n);
}

int main()
{
    read();
    lcs();
    print();
    return 0;
}
