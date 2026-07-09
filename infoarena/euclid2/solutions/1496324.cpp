#include <stdio.h>
#include <iostream>
using namespace std;

int euclid(int a, int b)
{
	if(b == 0)
		return a;
	else
		return euclid(b,a%b);

}
int main()
{
	FILE *f, *g;
	f = fopen("euclid2.in","r");
	g = fopen("euclid2.out","w");
	int T,a,b;
	fscanf(f,"%d %d",&a,&b);
	fprintf(g,"%d",euclid(a,b));
	return 0;
}