#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
using namespace std;

int* a;
int* b;
int** s;
int m, n;

int max (int a, int b)
{
    if (a > b)
        return a;
    return b;
}

struct aaa
{
    int cat;
    int* care;
};

aaa cmlsc()
{


    s = new int*[m + 2];

    for (int i = 0; i <= m; i++)
    {
        s[i] = new int[n + 2];
        s[i][0] = 0;
    }

    for (int j = 0; j <= n; j++)
            s[0][j] = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
                s[i + 1][j + 1] = s[i][j] + 1;
            else
                s[i + 1][j + 1] = max(s[i + 1][j], s[i][j + 1]);
        }
    }


    aaa f;
    f.cat = s[m][n];
    f.care = new int[f.cat];

    int* p;
    int k = s[m][n];
    p = new int[k];
    int i = m, j = n;
    while (i && j )
    {
        if (a[i - 1] == b[j - 1])
            p[--k] = a[i - 1], i--, j--;
        else if (s[i][j] == s[i - 1][j])
            i--;
        else
            j--;
    }

    for (int i = 0; i < f.cat; i++)
        f.care[i] = p[i];
    return f;
}

int main()
{
    ifstream in ("cmlsc.in");
    ofstream out ("cmlsc.out");

    in >> m >> n;

    a = new int[m];
    b = new int[n];

    for (int i = 0; i < m; i++)
        in >> a[i];

    for (int i = 0; i < n; i++)
        in >> b[i];
    aaa f = cmlsc();
    out << f.cat << "\n";
    for (int i = 0; i < f.cat; i++)
        out << f.care[i] << " ";

    return 0;
}
