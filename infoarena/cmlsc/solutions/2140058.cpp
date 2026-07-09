#include <iostream>
#include <fstream>

#define maxim(a, b) ((a > b) ? a : b)

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlcs.out");

int a[1025],b[1025],m,n,i,j,D[1025][1025],sir[1025],bst;


int main()
{
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(i=1;i<=n;i++)
        f>>b[i];


    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            if (a[i] == b[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);

    for (i = m, j = n; i; )
        if (a[i] == b[j])
            sir[++bst] = a[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;

    printf("%d\n", bst);
    for (i = bst; i; --i)
        printf("%d ", sir[i]);

    return 0;
}
