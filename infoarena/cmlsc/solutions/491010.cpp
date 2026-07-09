#include <stdio.h>
#include <stdlib.h>
FILE *f,*g;
int m,n,a[258],b[258];

int min(int x,int y){
 if(x>y) return x;
 else return y;
}

int main(){
  int i,j,max;
		f=fopen("cmlsc.in","r");
		g=fopen("cmlsc.out","w");

		fscanf(f,"%d %d",&m,&n);
		int x;   max=-2;
		for(i=1;i<=m;i++)
		  {
		   fscanf(f,"%d",&x);
		   a[x]++;
		   if(max<x) max=x;
		  }
		for(i=1;i<=n;i++)
		  {
		   fscanf(f,"%d",&x);           
		   b[x]++;
		   if(max<x) max=x;
		  }
		fclose(f);

		long nr=0;
		int k=0;
		
		for(i=1;i<=max;i++)
		  {
		   if(a[i]!=0 && b[i]!=0)
			{
			 nr+=min(a[i],b[i]);
			 k++;
			 b[k]=min(a[i],b[i]);
			 a[k]=i;
			}
		  }
		fprintf(g,"%ld\n",nr);

		for(i=1;i<=k;i++)
		  {
		   if(b[k]==1)
			 fprintf(g,"%d ",a[i]);
		   else
			 for(j=1;j<=b[k];j++)
			   {
				fprintf(g,"%d ",a[i]);
			   }
		  }
		fclose(f);
return 0;
}