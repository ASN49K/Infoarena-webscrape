#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>

using namespace std;
 
int a,b,tests;

int gcd(int a, int b) {
	int t;
	if (a<b) {
		t = a;
		a = b;
		b = t;
	}
	
	while (b!=0) {
		t = b;
		b = a % b;
		a = t;
	}
	
	return a;
}

int main(int argc, char **argv)
{
	FILE *f = fopen("euclid2.in","r");
	FILE *g = fopen("euclid2.out","w");
	fscanf(f,"%d",&tests);
	
	for (int t=0;t<tests;t++) {
		fscanf(f,"%d%d",&a,&b);
		fprintf(g,"%d\n",gcd(a,b));
	}

	return 0;
}

