#include<stdio.h>
FILE *in,*out;
int nr1, nr2,cm,i,t;
int main()
{
	in=fopen("euclid2.in","rt");
	out=fopen("euclid2.out","wt");
	fscanf(in,"%d",&t);
	for(int j=1;j<=t;j++)
	{
		fscanf(in,"%d %d",&nr1,&nr2);
		cm=0;
		if(nr1>nr2)
		{
			for(i=2;i<=nr2;i++)
				if( !(nr1%i) && !(nr2%i) )
					cm=i;
			if(cm)
				fprintf(out,"%d",cm);
			else
				fprintf(out,"0");
		}
		
		if(nr2>nr1)
		{
			for(i=2;i<=nr1;i++)
				if( !(nr1%i) && !(nr2%i) )
					cm=i;
			if(cm)
				fprintf(out,"%d",cm);
			else
				fprintf(out,"0");
		}
	
		if(nr1==nr2)
			fprintf(in,"%d",nr1);
	}
	return 0;
}
