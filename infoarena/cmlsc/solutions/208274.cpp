#include <stdio.h>

FILE *fin,*fout;
long n,m,z,i,j;
int a[1020],b[1020],v[1020];
int c[1020][1020];

int main()
{
	fin=fopen("cmlsc.in","r");
   fout=fopen("cmlsc.out","w");
   fscanf(fin,"%ld%ld",&n,&m);
   for(i=1;i<=n;i++) fscanf(fin,"%ld",&a[i]);
	for(i=1;i<=m;i++) fscanf(fin,"%ld",&b[i]);
	for(i=1;i<=n;i++)
   	for(j=1;j<=m;j++)
      	if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
         else
         	if(c[i-1][j]>c[i][j-1]) c[i][j]=c[i-1][j];
            else c[i][j]=c[i][j-1];
fprintf(fout,"%d\n",c[n][m]);
i=n; j=m;
do{
	if(a[i]==b[j])
   { z++; v[z]=a[i];
     i--; j--; c[n][m]--;}
   else
	   if(c[i-1][j]>c[i][j-1]) i--;
  		else j--;
}while((i>0) || (j>0) || (c[n][m]!=0));
for(i=z;i>=1;i--) fprintf(fout,"%d ",v[i]);
fprintf(fout,"\n");
fclose(fin); fclose(fout);
return 0;
}


