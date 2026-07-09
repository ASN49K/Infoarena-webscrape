#include<stdio.h>
#include<stdlib.h>
using namespace std;
int n,m,a[1024],b[1024],c[1024][1024],nr,i,j,v[1024];

int main()
{ 
	FILE *f,*g;
	f = fopen("cmlsc.in","r");
	g = fopen("cmlsc.out","w");
    
	fscanf(f,"%d %d", &m, &n);
    for(i = 1; i <= m; i++) 
        fscanf(f,"%d", &a[i]);
	for(i = 1; i <= n; i++)
        fscanf(f,"%d", &b[i]);
	for(i = 1; i <= m; i++) c[i][0] = 0;
	for(i = 1; i <= n; i++) c[0][j] = 0;
    for(i = 1; i <= m; i++)
		for(j = 1;  j <= n; j++)
			if(a[i] == b[j]) 
				c[i][j] = 1 + c[i-1][j-1];
             else
                if(c[i-1][j] > c[i][j-1])
					c[i][j] = c[i-1][j];
				  else c[i][j] = c[i][j-1];
 
    for (i = m, j = n; i > 0, j > 0; )
        if (a[i] == b[j]) {
            v[++nr] = a[i];
		i--;
		j--;
		}
         else 
			 if (c[i-1][j] < c[i][j-1])
              j--;
        else
             i--;
 
    fprintf(g,"%d\n", nr);
    for (i = nr; i > 0; i--)
        fprintf(g,"%d ", v[i]);
 
    return 0;
}
