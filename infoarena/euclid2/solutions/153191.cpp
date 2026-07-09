#include<stdio.h>
int a,b,i,minim,sem=0; FILE *f,*g;

void main()
{f=fopen("euclid2.in","r");
 g=fopen("euclid2.out","w");
 fscanf(f,"%d %d", &a, &b);
 if(a<b)minim=a;
	else minim=b;
 i=minim;
 do
 if(a%i==0&&b%i==0){fprintf(g,"%d\n",i);
		    sem=1;}
		    else i--;
                    while(sem==0);
}