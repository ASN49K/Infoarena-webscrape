#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b) {    
    if(!a)  
        return b;  
    while(b) {  
        if(a>b)  
            a-=b;  
        else  
            b-=a;  
    }
    return a;  
}

int main() {
	FILE *f, *g;
	int T,a,b;
	f=fopen("euclid.in", "r");
	g=fopen("euclid.out", "w");
	fscanf(f, "%d", &T);
	while(T--) {
		fscanf(f, "%d %d", &a,&b);
		fprintf(g, "%d\n", cmmdc(a,b));
	}
	fclose(f);
	fclose(g);
	return 0;
}
