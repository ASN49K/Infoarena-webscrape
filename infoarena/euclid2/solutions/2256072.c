#include <stdio.h>
int main()
{
	 
    FILE *fin, *fout;
    fin = fopen("euclid2.in", "r");
    fout = fopen("euclid2.out", "w");
 
    int n, a, b;
    fscanf(fin, "%d", &n);
    for(int i=1; i<=n; i++) {
        fscanf(fin, "%d%d", &a, &b);
        fprintf(fout, "%d\n", euclid(a, b));
    }
	return 0;
}


int euclid(int a,int b)
{
	int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
	return a;
}