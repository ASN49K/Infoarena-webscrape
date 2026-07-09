#include <cstdio>

#define LGMAX 1026

#define max(a, b) ((a > b) ? a : b)

using namespace std;

FILE *inFile = fopen ("cmlsc.in", "r");
FILE *outFile = fopen ("cmlsc.out", "w");

int na;
int nb;
int a[LGMAX];
int b[LGMAX];
int s[LGMAX][LGMAX];

void readArray(int n, int x[LGMAX])
{
    for (int i = 1; i <= n; ++i)
        fscanf (inFile, "%d ", &x[i]);
}

void read()
{
    fscanf (inFile, "%d %d\n", &na, &nb);

    readArray(na, a);
    readArray(nb, b);
}

void solve()
{
    for (int i = 1; i <= na; ++i)
        for (int j = 1; j <= nb; ++j)
            if (a[i] == b[j])
                s[i][j] = 1 + s[i - 1][j - 1];
            else
                s[i][j] = max (s[i - 1][j], s[i][j - 1]);
}

void print(int i, int j)
{
    if (s[i][j] == 0)
        return;

    if (a[i] == b[j])
    {
        print (i - 1, j - 1);
        fprintf (outFile, "%d ", a[i]);
        return;
    }

    if (s[i - 1][j] > s[i][j - 1])
        print (i - 1, j);
    else
        print (i, j - 1);
}

int main()
{
    read();
    solve();

    fprintf (outFile, "%d\n", s[na][nb]);
    print(na, nb);

    return 0;
}
