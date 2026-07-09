#include <stdlib.h>
#include <stdio.h>
int cmmdc(int a, int b){
	if(a==b)
		return a;
	if(a > b)
		return cmmdc(a-b, b);
	else
		return cmmdc(a, b-a);
}
void main(){

	FILE *ptr, *ptrO;
	ptr = fopen("input.in", "r");
	ptrO = fopen("output.out", "w");
	int numbers=0;
	fscanf(ptr, "%d", &numbers);
	int a=0, b=0;
	while(numbers){
		fscanf(ptr, "%d %d", &a, &b);
		fprintf(ptrO, "%d\n", cmmdc(a, b));
		numbers--;
	}
	fclose(ptr);
	fclose(ptrO);
}