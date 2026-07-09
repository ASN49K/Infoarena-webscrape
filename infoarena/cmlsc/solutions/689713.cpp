#include <fstream.h>
using namespace std;
int an,bn,a[1025],b[1025],ab[1025],i,j,k,cur;

int main () {
	FILE *f,*g;
	f=fopen("cmlsc.in", "r");
	g=fopen("cmlsc.out", "w");
	fscanf(f, "%d %d", &an, &bn);
	if (an>bn)
	{
		for (i=1; i<=an; i++) fscanf(f, "%d", &a[i]);
		for (i=1; i<=bn; i++) fscanf(f, "%d", &b[i]);
	}
	else 
	{
		for (i=1; i<=an; i++) fscanf(f, "%d", &b[i]);
		for (i=1; i<=bn; i++) fscanf(f, "%d", &a[i]);
		i=bn;
		bn=an;
		an=i;
	}
	k=0;
	for (i=1; i<=an; i++)
	{
		for (j=1; j<=i; j++)
		if (a[i]==b[j])
			{
				ab[++k]=a[i];
				b[i]=257;
			}				
	}
	//for (i=1; i<=an; i++) fprintf(g, "%d ", a[i]); fprintf(g, "\n");
	//for (i=1; i<=bn; i++) fprintf(g, "%d ", b[i]); fprintf(g, "\n");
	fprintf(g, "%d\n", k);
	for (i=1; i<=k; i++) fprintf(g, "%d ", ab[i]);
	fclose(f); fclose(g);
	return 0;
}