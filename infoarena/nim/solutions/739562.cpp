#include<stdio.h>
using namespace std;

FILE *f = fopen("nim.in","r");
FILE *g = fopen("nim.out","w");

int main()
{
	int t;
	fscanf(f,"%d",&t);
	
	for(int i=1; i<=t; i++){
	
		
		int rezultat = 0;
		int n ;
		fscanf(f,"%d",&n);
		
		for(int j=1; j<=n; j++){
		int a;
		fscanf(f,"%d",&a);
		rezultat ^= a;
		}
		
		if(rezultat != 0)
			fprintf(g,"DA\n");
		else
			fprintf(g,"NU\n");
	
	}		
	

return 0;
}
