#include <fstream>
#include <cstdio>
using namespace std;
int processPair(long a, long b) {
	int r = a % b;
	while (r > 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main(int argc, char** argv) {
	FILE * f, *g;
	f = fopen ("euclid2.in", "r");
	g = fopen ("euclid2.out", "w");

	int numberOfEntries;
	fscanf(f, "%d", &numberOfEntries);
	while (numberOfEntries > 0) {
		long int a,b;
		fscanf(f, "%ld%ld", &a, &b);
		fprintf(g, "%d\n", processPair(a, b)); 
		
		numberOfEntries --;
	}
	fclose (f);
	fclose (g);
	return 0;
}
