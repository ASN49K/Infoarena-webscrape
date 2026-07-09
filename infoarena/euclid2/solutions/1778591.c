#include<stdio.h>
int cmmdc(int a, int b)
{
	if(b==0) return a;
        return cmmdc(b,a%b);
}

int main()
{	int T,A,B;
	FILE*fin=fopen("euclid2.in","r");
	FILE*fout=fopen("euclid2.out","w");
	fscanf(fin,"%d",&T);
	for(int i=0;i<T;i++)
	{ fscanf(fin,"%d%d",&A,&B);
	  fprintf(fout,"%d\n",cmmdc(A,B));
}
fclose(fin);
fclose(fout);
return 0;
}
