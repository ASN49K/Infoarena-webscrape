#include <fstream>
#include <vector>
#include <algorithm>

#define BF 1
#define F  2
#define B  3

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

typedef vector<int> Vektor;
typedef vector<int>::iterator Iterator;
typedef vector<int>::const_iterator cIterator;

vector<int> x, y;
int n, m, i, j, temp;
int a[1030][1030];
int b[1030][1030];
int write_vector (const Vektor& t)
{
    cIterator i;
    for (i=t.begin(); i<t.end(); i++)
        g << *i << " ";
    g << "\n";
    return 0;
}
int write_matrix ()
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            g << a[i][j] << " ";
        }
        g << "\n";
    }
    return 0;
}
int write_sol (int i, int j)
{
    if (!i || !j) return 0;

    if (b[i][j] == BF)
    {
        write_sol (i-1, j-1);
        g << x[i] << " ";
    }
    else
    {
        if (b[i][j] == F) write_sol (i-1, j);
        else              write_sol (i, j-1);
    }
}
int main()
{
    f >> n >> m;
    x.push_back(0);
    y.push_back(0);

    for (i=1; i<=n; i++)
    {
        f >> temp;
        x.push_back(temp);
    }
    for (i=1; i<=m; i++)
    {
        f >> temp;
        y.push_back(temp);
    }
    n++; m++;

    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            if (x[i] == y[j])
            {
                a[i][j] = a[i-1][j-1] + 1;
                b[i][j] = BF;
            }
            else
            {
                if (a[i-1][j] > a[i][j-1])
                {
                    a[i][j] = a[i-1][j];
                    b[i][j] = F;
                }
                else
                {
                    a[i][j] = a[i][j-1];
                    b[i][j] = B;
                }
            }
        }
    }

    g << a[n][m] << "\n";
    write_sol(n, m);
}
