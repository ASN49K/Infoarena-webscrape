#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

void euclid(int a, int b, FILE* output)
{
	int r; 
	if(a > b){
		while(1){
			r = a % b; 
			if(r == 0){
				fprintf(output, "%i", b); 
				break; 
			}
			a = b;  
			b = r; 
		}
	}else {
		while(1){
			r = a % b; 
			if(r == 0){
				fprintf(output, "%i", b); 
				break; 
			}
			a = b; 
			b = r; 
		}
	} 
} 

int main()
{
	FILE* input; 
	FILE* output; 
	output = fopen("euclid2.out", "a"); 
	input = fopen("euclid2.in", "r"); 
	if(input == NULL){
		printf("NU s-a deschis fisierul\n");
	} 
	int T; 
	fscanf(input, "%i", &T); 
	int i; 
	for(i = 0; i < T; i++){
		int a,b; 
		scanf(input, "%i", &a); 
		scanf(input, "%i", &b); 
		euclid(a, b, output); 
	} 

	fclose(input); 
	fclose(output);

	return 0; 
}