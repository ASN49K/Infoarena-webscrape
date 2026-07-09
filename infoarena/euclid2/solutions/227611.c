#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int __cmmdc1(int a, int b) {
	if(!b)
		return a;
	else
		return __cmmdc1(b, a % b);
}

int cmmdc1(int a, int b) {
	if(a >= b)
		return __cmmdc1(a, b);
	else
		return __cmmdc1(b, a);
}

int cmmdc2(int a, int b) {
	int k, m;
	
	k = 0;
	while(!(a&1)) {
		k++;
		a >>= 1;
	}
	m = 0;
	while(!(b&1)) {
		m++;
		b >>= 1;
	}
	
	while(1) {
	if(a >= b) {
		a -= b;
		if(!a) break;
		while(!(a&1))
			a >>= 1;
	} else {
		b -= a;
		if(!b) break;
		while(!(b&1))
			b >>= 1;
	}
	}
	
	if(a > 0) {
		if(k >= m)
			return a << m;
		else
			return a << k;
	} else {
		if(k >= m)
			return b << m;
		else
			return b << k;
	}
}

int main() {
FILE *f, *g;
long end, start = clock();
int i, a, b, /*c, d,*/ T;

/*
f = fopen("in", "wt");

srand(time(NULL));
for(i = 0; i < 100000; i++) {
	a = rand();
	b = rand();
	c = rand();
	d = rand();
	fprintf(f, "%d %d\n", (a << 16) + b, (c << 16) + d);
}

fclose(f);
*/


f = fopen("euclid2.in", "rt");
g = fopen("euclid2.out", "wt");
fscanf(f, "%d", &T);

for(i = 0; i < T; i++) {
	fscanf(f, "%d", &a);
	fscanf(f, "%d", &b);
	fprintf(g, "%d\n", cmmdc2(a, b));
}

fclose(f);
fclose(g);


end = clock();
printf("%f\n", (float) (end - start) / CLOCKS_PER_SEC);

return 0;
}
