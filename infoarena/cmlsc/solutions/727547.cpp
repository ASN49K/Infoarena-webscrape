#include <cstdio>
#define maxim(a, b) ((a>b)? a : b)

using namespace std;

FILE * iFile;
FILE * oFile;

int m, n, a[1024], b[1024], d[1024][1024], sir[2024], bst;

int main()
{
    iFile = fopen("cmlsc.in", "r");
    oFile = fopen("cmlsc.out", "w");

    int i, j;

    fscanf(iFile, "%d %d", &m, &n);

    for(i=1;i<=m;i++)
        fscanf(iFile, "%d", &a[i]);
    for(i=1;i<=n;i++)
        fscanf(iFile, "%d", &b[i]);

    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else d[i][j] = maxim(d[i-1][j], d[i][j-1]);


    for(i=m,j=n;i;)
    {
        if(a[i] == b[j])
            sir[++bst] = a[i], --i, --j;
        else if(d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;
    }

    fprintf(oFile, "%d\n", bst);
    for(i=bst;i;--i)
        fprintf(oFile, "%d ", sir[i]);


    fclose(iFile);
    fclose(oFile);

    return 0;
}

