#include<stdio.h>
int euclid(int a,int b)
{int r=0,x=a,y=b;
do{ r=x%y;
    x=y;
    y=r;}
    while(r!=0);
return x;
}

int main()
{FILE *f,*g;
f=fopen("euclid2.in","r");
g=fopen("euclid2.out","w");
int t=0,a=0,b=0,i=0,c=0;
fscanf(f,"%d",&t);
for(i=1;i<=t;i++) {	
    fscanf(f,"%d %d",&a,&b);
    fprintf(g,"%d\n",euclid(a,b));}
fprintf(g,"\n");
fclose(f);
fclose(g);
return 0;
}
