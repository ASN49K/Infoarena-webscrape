#include <stdio.h>
#include <stdlib.h>
#define FOR(i,a,b) for(i=a;i<=b;++i)
#define N 1040
int a[N],b[N];
int lcs[N][N];
int m,n;
int d[N];
int main(void){
	int k,h,i;
	freopen("cmlsc.in","rt",stdin);
	freopen("cmlsc.out","wt",stdout);
	fscanf(stdin,"%d%d",&n,&m);
	FOR(i,1,n)
		fscanf(stdin,"%d",&a[i]);
	FOR(i,1,m)
		fscanf(stdin,"%d",&b[i]);
	FOR(k,1,n)
		FOR(h,1,m)
			if (a[k]==b[h])
				lcs[k][h]=lcs[k-1][h-1]+1;
			else{
				if ( lcs[ k - 1 ] [ h ] > lcs[ k ] [ h - 1 ] )
					lcs[ k ] [ h ] = lcs[ k - 1 ][ h ];
              			else
              				lcs[ k ] [ h ] = lcs[ k ][ h - 1 ];
			}
	
	fprintf(stdout,"%d\n",lcs[n][m]);

	for (i=0, k=n, h=m; lcs[k][h]; )
    		if (a[k]==b[h]){
			d[i++]=a[k];
			k--;
			h--;
		}
       		else
       		if ( lcs [ k ][ h ] == lcs[ k - 1 ][ h ])
			k--;
          	else
          		h--;
	for (k=i-1;k>=0; k--)
		fprintf(stdout,"%d ",d[k]);
	exit(0);
}

				
