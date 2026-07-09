#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int m, n;
int mat[1030][1030];
int first[1030];
int second[1030];

void Debug()
{
    for (int i=1; i<=m; i++, cerr<<"\n")
        for (int j=1; j<=n; j++)
            cerr<<mat[i][j]<<"  ";

}
void Afisare(int i = m, int j = n)
{
    if (j < 1)
    {
        i--;
        j = n;
        return;
    }

    if (i < 1)
        return;

    if (first[i] == second[j])
    {
        Afisare(i-1, j-1);
        printf("%d ", first[i]);
        return;
    }

    else
    {
        if (mat[i][j-1] > mat[i-1][j])
            Afisare(i, j-1);
        else
            Afisare(i-1, j);
    }
}

void Solve()
{
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            if (first[i] == second[j])
                mat[i][j] = max(max(mat[i-1][j-1]+1, mat[i][j-1]), mat[i-1][j]);
            else
                mat[i][j] = max(mat[i][j-1], mat[i-1][j]);
}

void Read()
{
    scanf("%d %d\n", &m, &n);
    for (int i=1; i<=m; i++)
        scanf("%d ", &first[i]);
    scanf("\n");
    for (int i=1; i<=n; i++)
        scanf("%d ", &second[i]);
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    Read();
    Solve();
    //Debug();
    printf("%d\n", mat[m][n]);
    Afisare();
    return 0;
}
