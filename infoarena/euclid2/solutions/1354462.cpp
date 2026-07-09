#include <cstdio>

typedef int te;

int main() {
	FILE * iff = fopen("euclid2.in","r");
	FILE * off = fopen("euclid2.out","w");
	te T,a,b;
	fscanf(iff,"%d",&T);
	while (T--) {
		fscanf(iff, "%d %d\n",&a,&b);
		while (b != 0) {
			te r = a % b;
			a = b;
			b = r;
		}
		fprintf(off,"%d\n",a);
	}
	return 0;
}