#include<stdio.h>
FILE *fin,*fout;
int main()
{
    fin=fopen("euclid2.in","r");
	fout=fopen("euclid2.out","w");
	int a,b,r;
	int n;
	fscanf(fin,"%d",&n);
	int i;
	for(i=1;i<=n;i++){
	    fscanf(fin,"%d%d",&a,&b);
        r=a%b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;


        }
            fprintf(fout,"%d\n",a);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
