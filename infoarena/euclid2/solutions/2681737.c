#include <stdio.h>

int cmmdc(int a, int b){
    while(a != b){
        if(a > b)
            a -= b;
        else
            b -= a;
    }
    
    return a;
}

int main(void) {
	// your code goes here
	
	FILE *in = fopen("euclid2.in", "rt");
	FILE *out = fopen("euclid2.out", "wt");
	
	int n, a, b;
	fscanf(in, "%d", &n);
	for(int i = 0; i < n; i++){
	    fscanf(in, "%d %d", &a, &b);
	    fprintf(out, "%d\n", cmmdc(a, b));
	}
	
	fclose(in);
	fclose(out);
	
	return 0;
}