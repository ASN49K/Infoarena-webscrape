#include <iostream>
#include <fstream>
using namespace std;

int maxim(int a, int b)
{
    if (a > b) return a;
    else return b;
}

main()
{
    ifstream f1("testin.txt");
    int n, m, a[1024], b[1024], i, j, c[1024][1024]={0}, bst=1, sir[1024];
    f1 >> n >> m;

    for (i = 1; i <= n; i++)
        f1 >> a[i];
    for (i = 1; i <= m; i++)
        f1 >> b[i];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            if (a[i] == b[j]) c[i][j] = c[i-1][j-1] + 1;
            else c[i][j]=maxim(c[i-1][j],c[i][j-1]);
        }

    for (i = n, j = m; i > 0; )
        if (a[i] == b[j])
        {
            sir[bst] = a[i];
            bst++;
            i--;
            j--;
        }
        else if (c[i-1][j] < c[i][j-1]) j--;
            else i--;

    cout << bst << " ";
    for (i = bst-1; i > 0; i--)
        cout << sir[i] << " ";
}
