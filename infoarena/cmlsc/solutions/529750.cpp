#include<stdio.h>
FILE*f=fopen("cmlsc.in","r");
FILE*g=fopen("cmlsc.out","w");
int max(int a,int b){
	if(a>b)
		return a;
	else
		return b;
}
int k,i,j,t,nr1,nr2,a[1025][1025],sol[1025],m1[1025],m2[1025];

int main() {
	fscanf(f,"%d%d",&nr1,&nr2);
	for(i=1;i<=nr1;i++)
		fscanf(f,"%d",&m1[i]);
	for(i=1;i<=nr2;i++)
		fscanf(f,"%d",&m2[i]);
	
	
	for(i=1;i<=nr1;i++)
		for(j=1;j<=nr2;j++)
			if(m1[i]==m2[j])
				a[i][j]=1+a[i-1][j-1];
			else
				a[i][j]=max(a[i-1][j],a[i][j-1]);
			
	for(i=nr1,j=nr2;i;)
		if(m1[i]==m2[j]){
			sol[++k]=m1[i];
			i--;
			j--;
		}else
			if(a[i-1][j]>=a[i][j-1])
				i--;
			else
				j--;
	fprintf(g,"%d\n",k);
	for(i=k;i;i--)
		fprintf(g,"%d ",sol[i]);
	fclose(g);
	fclose(f);
	return 0;
}
