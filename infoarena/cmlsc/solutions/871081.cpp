#include <stdio.h>
FILE *in,*out;
 
#define maxim(a, b) ((a > b) ? a : b)
 
int m, n, a[1024], b[1024], d[1024][1024], sir[1024], bst;
 
int main(void)
{
	in=fopen("cmlsc.in","rt");
	out=fopen("cmlsc.out","wt");
    fscanf(in,"%d %d", &m, &n);
    for(int i=1;i<=m;++i)
        fscanf(in,"%d", &a[i]);
    for(int j=1;j<=n;++j)
        fscanf(in,"%d", &b[j]);
	
   	for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            if (a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = maxim(d[i-1][j], d[i][j-1]);
 
    for (int i = m, j = n; i; )
        if (a[i] == b[j])
            sir[++bst] = a[i], --i, --j;
        else if (d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;
 
    fprintf(out,"%d\n", bst);
    for (int i = bst; i; --i)
        fprintf(out,"%d ", sir[i]);
	fclose(in);
	fclose(out);	
    return 0;
}