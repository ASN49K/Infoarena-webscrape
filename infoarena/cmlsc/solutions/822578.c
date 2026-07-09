#include <stdio.h>
#include <stdlib.h>
int main(){
	freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
	int n, m, *a, *b, i, j, size = 0, *longest, *aux, au;
	

	scanf("%d%d",&n,&m);
	
	a = (int *)malloc(n * sizeof(int *));
	b = (int *)malloc(m * sizeof(int *));

	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);
	for(i = 0; i < m; i++)
		scanf("%d",&b[i]);
	
	if(n < m){
		longest = (int *) malloc(n * sizeof(int *));
	}else
		longest = (int *) malloc(m * sizeof(int *));

		

	for( i = 0; i < m; i++){
		for( j = 0; j < n; j++){
			if(b[i] == a[j])
				longest[size++] = a[j];
		}
	}
	printf("%d\n",size);
	for( i = 0; i < size; i++)
		printf("%d ", longest[i]);

}
