#include <stdio.h>
#include <stdlib.h>

int updateElem(int left, int top, int* elem){
	if( left > top ){ 
		elem[0] = left;
		elem[1] = 1;//stores direction .. 1 = left; 2 = up; 0 = diagonal	
	}
	else{ //top element bigger
		elem[0] = top;
		elem[1] = 2;	
	}
}

void print( int*** x ){
	printf("x = %d\n", sizeof(x[0]));
	int i,j;	
	for( j = 0; j < 4; j++){
		for( i = 0; i < 6; i++ )
			printf("%d ", x[i][j][0]);
		printf("\n");
	}

}

int main(){

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "wr", stdout);
	
	int m,n,i,j;
	scanf("%d %d", &m, &n);

	int a[m],b[n];
//	int c[m][n][2];
	int*** c; 
	//printf("m = %d   ",m); 
	//printf("  n = %d   ",n); 
	c = malloc(sizeof(int**) * (m + 1) );
	for( i = 0; i <= m; i++){
		c[i] = malloc(sizeof(int*) * (n + 1 ));
		for( j = 0; j <= n; j++)
			c[i][j] = malloc(sizeof(int) * 2 );
	}

	//printf(" c = %d", sizeof(c));
	//printf(" c[0] = %d", sizeof(c[0]));
	//printf(" c[0][0] = %d", sizeof(c[0][0]));

	for( i = 0; i < m; i++)
		scanf("%d", &a[i]);//read vectors

	for( i = 0; i < n; i++)
		scanf("%d", &b[i]);

	for( i = 0; i <= m; i++)  //initialise columns with 0
		c[i][0][0] = 0;	

	for( i = 0; i <= n; i++)
		c[0][i][0] = 0;	

	for( i = 1; i <= m; i++ ) //compute lengths
		for( j = 1; j <= n; j++){
			if(a[i-1] == b[j-1]){
				c[i][j][0] = c[i-1][j-1][0] + 1;
				c[i][j][1] = 0;
			}
			else
				updateElem(c[i-1][j][0],c[i][j-1][0], c[i][j]);			
		}

	//print(c);	
	
	printf("%d\n", c[m][n][0]);//length of the lcs
	i = m; 
	j = n;
	int lcs[1024], count = 0;
	
	while( i > 0 && j > 0){
		if(c[i][j][1] == 0){ //diagonal
			lcs[count] = a[i-1];
			count++;
			i--;
			j--;
		}
		else {if(c[i][j][1] == 1 ) 
					i--;//left
				else
					j--;//up
				}
		}
	//printf("count = %d", count);
	for(i = count - 1; i >= 0; i--)
		printf("%d ", lcs[i]);

	for( i = 0; i <= m; i++){   //free memory
		for( j = 0; j <= n; j++)
			free(c[i][j]);
		free(c[i]);
	}
	free(c);
	
	return 0;
}
