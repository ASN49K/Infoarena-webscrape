#include <iostream>
#include <cstdio>
using namespace std;

int A[1025], B[1025], M[1025][1025],
    m, n,
    l, v[1025]; // pentru afisare

void citire()
{
    freopen("cmlsc.in", "r", stdin);
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= m; ++i) scanf("%d", &A[i]);
    for(int i = 1; i <= n; ++i) scanf("%d", &B[i]);
    fclose(stdin);
}

void LSC()
{
    int x, y;
    x = 1;
    while(x <= m)
        {
            y = 1;
            while(y <= n)
                {
                    if(A[x] == B[y]) M[x][y] = M[x - 1][y - 1] + 1;
                    else M[x][y] = (M[x][y - 1] > M[x - 1][y]) ? M[x][y - 1] : M[x - 1][y];
                    ++y;
                }
            ++x;
        }
}

void backtrack()
{
    int x = m, y = n, L = l;
    while(x && L)
        {
            while(y && L)
                {
                    if(A[x] == B[y])
                        {
                            v[L--] = A[x];
                            x--;
                            y--;
                        }
                    if(M[x - 1][y] > M[x][y - 1]) x--;
                    else y--;
                }
        }
}

void afisare()
{
    freopen("cmlsc.out", "w", stdout);
    printf("%d\n", l);
    for(int i = 1; i <= l; ++i) printf("%d ", v[i]);
    /*for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
                printf("%d ", M[i][j]);
            printf("\n");
        }*/
    fclose(stdout);
}

int main()
{
    citire();
    LSC();
    l = M[m][n];
    backtrack();
    afisare();

    return 0;
}
