#include<stdio.h>
FILE *fin,*fout;
int main()
{
    fin=fopen("euclid2.in","r");
	fout=fopen("euclid2.out","w");
	long long a,b,r;
	int n;
	fscanf(fin,"%d",&n);
	int i;
	for(i=1;i<=n;i++){
	    fscanf(fin,"%lld%lld",&a,&b);
        r=a%b;
        while(r!=0)
        {
            r=a%b;
            a=b;
            b=r;


        }
            fprintf(fout,"%lld\n",a);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
