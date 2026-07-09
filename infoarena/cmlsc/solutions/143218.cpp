#include<stdio.h>
long int n,m,i,j,a[1030],b[1030],cmlsc[1030][1030],c[1030],sol,max;
int main()
{
	FILE *f,*g;f=fopen("cmlsc.in","r");g=fopen("cmlsc.out","w");
	fscanf(f,"%ld%ld",&n,&m);
	for(i=0;i<n;i++)fscanf(f,"%ld",&a[i]);
	for(j=0;j<m;j++)fscanf(f,"%ld",&b[j]);
	for(i=0;i<n;i++) if(a[i]==b[0])cmlsc[i][0]=1;
	for(j=1;j<m;j++) if(a[0]==b[j])cmlsc[0][j]=1;
	for(i=1;i<n;i++)
	 for(j=1;j<m;j++)
	  { if(a[i]==b[j]) cmlsc[i][j]=cmlsc[i-1][j-1]+1;
	    else cmlsc[i][j]=(cmlsc[i-1][j]>cmlsc[i][j-1])?cmlsc[i-1][j]:cmlsc[i][j-1];
	  }
	sol=cmlsc[n-1][m-1];max=sol;
	fprintf(g,"%ld\n",sol);
	if(!sol){fcloseall();return 0;}
	i=n-1;j=m-1;
	while(i&&j&&max)
	{ if(cmlsc[i-1][j]==max){i--;continue;}
	  if(cmlsc[i][j-1]==max){j--;continue;}
	  c[max-1]=a[i];i--;j--;max--;
	}
	if(max)c[max-1]=a[i];
	for(i=0;i<sol;i++) fprintf(g,"%ld ",c[i]);
	fcloseall();
	return 0;
}

