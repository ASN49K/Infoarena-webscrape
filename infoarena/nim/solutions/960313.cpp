#include <cstdio>
using namespace std;

FILE *f=fopen ("nim.in","r");
FILE *g=fopen ("nim.out","w");

int main(){
	int n,t,i,j,s,x;
	
	fscanf (f,"%d",&t);
	
	for (j=1;j<=t;++j){
		fscanf (f,"%d",&n);
		s=0;
		for (i=1;i<=n;++i){
			fscanf (f,"%d",&x);
			s^=x;
		}
		if (s==0){
			fprintf (g,"NU");
		}
		else{
			fprintf (g,"DA");
		}
		fprintf (g,"\n");
	}
	
	return 0;
}
