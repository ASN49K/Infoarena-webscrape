#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int a[1024], b[1024];

typedef struct{
	uint8_t nr;
	uint8_t sens;
}SC;

SC c[1025][1025];

#define IJ 0
#define I 1
#define J 2

int main()
{
	//Deschidere fisiere
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	int n, m, i, j, k;

	//Citire date
	scanf("%d%d", &n, &m);
	for(i=0;i<n;i++)
		scanf("%d", a + i);
	for(i=0;i<m;i++)
		scanf("%d", b + i);

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(a[i] == b[j]){
				c[i][j].nr = c[i-1][j-1].nr + 1;
				c[i][j].sens = IJ;
			}
			else{
				if(c[i-1][j].nr > c[i][j-1].nr){
					c[i][j].nr = c[i-1][j].nr;
					c[i][j].sens = I;
				}
				else {
					c[i][j].nr = c[i][j-1].nr;
					c[i][j].sens = J;
				}

			}

	printf("%d\n", c[n-1][m-1].nr);
	i = n-1;
	j = m-1;
	k = 0;

	while(i >=0 && j >= 0){
		if(c[i][j].sens == IJ){
			b[k++] = a[i];
			i--;
			j--;
		}
		else if(c[i][j].sens == I)
			i--;
		else
			j--;
	}

	for(;k--;)
		printf("%d ", b[k]);

	return 0;
}
