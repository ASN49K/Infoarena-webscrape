#include <cstdio>
using namespace std;
int euclid(int a,int b){
		int r=a%b;
		while(r)
			a=b,b=r,r = a%b;
		return b;
	}

int main(){
	FILE *f = fopen("euclid2.in","r");
	FILE *g = fopen("euclid2.out","w");
	int T,a,b;
	fscanf(f,"%d",&T);
	while(T){
		fscanf(f,"%d%d",&a,&b);
		fprintf(g,"%d\n",euclid(a,b));
		T--;
		}
	fclose(f);
	fclose(g);
	}
