#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	long a, b, c;
	FILE * in = fopen("euclid2.in", "rt");
	FILE * out = fopen("euclid2.out", "wt");
	c = fscanf(in, "%d", &n);
	for(int i = 0; i < n; i++){
		c = fscanf(in, "%li%li", &a, &b);
		if(a % b == 0)
			fprintf(out, "%li\n", b);
		else if(b % a == 0)
			fprintf(out, "%li\n", a);
		else{
			if(a > b)
				c = a % b;
			else c = b % a;
			while(c > a || c > b){
				if(c > a)
					c = c % a;
				else c = c % b;
			}
			fprintf(out, "%li\n", c);
		}
	}
	fclose(in);
	fclose(out);
	return 0;
}
