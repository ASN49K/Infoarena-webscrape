#include<stdio.h>
#include<stdlib.h>
using namespace std;
int n,m,a[1025],b[1025],c[1025][1025],nr,i,j,v[1025];

int main()
{ 
	FILE *f,*g;
	f = fopen("cmlsc.in","r");
	g = fopen("clmsc.out","w");
    
	fscanf(f,"%d %d", &m, &n);
    for(i = 0; i < m; i++) 
        fscanf(f,"%d", &a[i]);
	for(i = 0; i < n; i++)
        fscanf(f,"%d", &b[i]);
    for(i = 0; i < m; i++)
		for(j = 0;  j < n; j++)
			if(a[i] == b[j]) 
				c[i][j] = 1 + c[i-1][j-1];
             else
                if(c[i-1][j] > c[i][j-1])
					c[i][j] = c[i-1][j];
				  else c[i][j] = c[i][j-1];
 
    for (i = m-1, j = n-1; i >= 0, j >= 0; )
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