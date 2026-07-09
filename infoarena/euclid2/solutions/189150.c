#include <stdio.h>  

int T;
int x,y,s;


int cmmdc(int a, int b)
{
	if(b==0) return a;
	return cmmdc(b,a%b);
}


int main(void)
{
	int i;
	
	FILE *f1=fopen("euclid2.in","r");
	FILE *f2=fopen("euclid2.out","w");
	
	fscanf(f1,"%d",&T);
  for(i=0;i<T;i++) 
	{
		fscanf(f1,"%d %d",&x,&y);
		s=cmmdc(x,y);
		fprintf(f2,"%d\n",s);
	}
	fclose(f1);fclose(f2);

	return 0;
} 