#include<stdio.h>
#define maxim(a, b) ((a > b) ? a : b)
int n,i,j,m,v1[1024],v2[1024],sol[1024],bst;
int ma[1024][1024];
int main()
{
 FILE *fin=fopen("cmlsc.in","r");
 FILE *fout=fopen("cmlsc.out","w");
 fscanf(fin,"%d %d",&m,&n);
 for(i=1;i<=m;i++)
     fscanf(fin,"%d",&v1[i]);
 for(i=1;i<=n;i++)
     fscanf(fin,"%d",&v2[i]);
 for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
	    if(v1[i]==v2[j])
		  ma[i][j]=1+ma[i-1][j-1];
	    else
		  ma[i][j]=maxim(ma[i-1][j],ma[i][j-1]);
 for(i=m,j=n;i>0;)
	if(v1[i]==v2[j])
	   {
	    sol[bst++]=v1[i];
	    i--;
	    j--;
	   }
	else
	   if(ma[i-1][j]<ma[i][j-1])
		 j--;
        else
		 i--;
 fprintf(fout,"%d\n",bst);
 for(i=bst-1;i>=0;i--)
	fprintf(fout,"%d ",sol[i]);
return 0;
}

