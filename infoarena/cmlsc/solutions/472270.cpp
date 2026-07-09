#include <stdio.h>
#define max(a,b) ( (a>b)?a:b )
#define nMax 1024
int M,N,a[nMax], b[nMax] ,lc[nMax][nMax],lcst[nMax],max;

int main(){ 
	int i,j;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&M , &N ) ;
	for( i = 1 ; i <= M ; i++ ) 
		scanf("%d", &a[i]);
	for( i = 1 ; i <= N ; i++ )
		scanf("%d", &b[i]);
		for( i = 1 ; i <= M ; i++ ) 
			for( j = 1; j <= N ; j++) 
				if( a[i] == b[j] )
					lc[i][j] = 1 + lc[i-1][j-1];
				else
					lc[i][j] = max(lc[i-1][j],lc[i][j-1]);
		max  = 0;	
		for( i =M, j = N; i ;)
			if( a[i]==b[j] ){
				lcst[++max] = a[i];	
				i--;	
				j--;
			}
			else if( lc[i][j-1] > lc[i-1][j] )
				j--;
			     else
				i--;
		printf("%d\n",max);
		for(i = max ; i ;i-- )
		printf("%d ",lcst[i]);
	

return 0;

}
