#include <stdlib.h>
#include <stdio.h>
int cmmdc(int a, int b){
	if( b == 0 )
		return a;
	else
		return (b, a%b);
}
int main(){

	FILE *ptr, *ptrO;
	ptr = fopen("euclid2.in", "r");
	ptrO = fopen("euclid2.out", "w");
	int numbers=0;
	if(fscanf(ptr, "%d", &numbers) == 0)
		printf("Error reading");
	int a=0, b=0;
	while(numbers){
		if(fscanf(ptr, "%d %d", &a, &b) == 0)
			printf("Error reading\n");
		fprintf(ptrO, "%d\n", cmmdc(a, b));
		numbers--;
	}
	fclose(ptr);
	fclose(ptrO);
	return 0;
}