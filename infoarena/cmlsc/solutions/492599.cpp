#include <iostream>
#include<cstdio>
using namespace std;
int a[1024], b[1024], c[1024], i, j, m, n, k=0;
int main()
{
    FILE *f=fopen("cmlsc.in", "r");
    FILE *g=fopen("cmlsc.out", "w");
    fscanf(f, "%d%d", &m, &n);
    for(i=0; i<m; i++)
        fscanf(f, "%d", &a[i]);
    for(i=0; i<n; i++)
        fscanf(f, "%d", &b[i]);
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            if(a[i]==b[j])
            {
				c[k]=a[i];
				k++;
            }
    fprintf(g, "%d\n", k);
    for(i=0; i<k; i++)
        fprintf(g, "%d ", c[i]);
    fclose(f);
    fclose(g);
    return 0;
}
