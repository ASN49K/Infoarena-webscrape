#include <cstdio>
#include <algorithm>
using namespace std;

FILE *f=fopen ("cmlsc.in","r");
FILE *g=fopen ("cmlsc.out","w");

int a[1025],b[1025],D[1025][1025],sir[1025];
int main(){
	int x,y,i,j;
	
	fscanf (f,"%d%d",&x,&y);
	
	for (i=1;i<=x;++i) fscanf (f,"%d",&a[i]);
	for (i=1;i<=y;++i) fscanf (f,"%d",&b[i]);
	
	for (i=1;i<=x;++i){
		for (j=1;j<=y;++j){
			if (a[i]==b[j]) D[i][j]=D[i-1][j-1]+1;
			else D[i][j]=max(D[i-1][j],D[i][j-1]);
		}
	}
	
	fprintf (g,"%d\n",D[x][y]);
	int r=0;
	for (i=x,j=y;i;){
		if (a[i]==b[j])  {
			sir[++r]=a[i];
			--i;
			--j;    
		}			
		else{ 
			if (D[i-1][j]<D[i][j-1]) --j;     
			else --i;
		}
	}		
	for (i=D[x][y];i;--i)   fprintf(g,"%d ", sir[i]); 
	
	return 0;
}
