#include <stdio.h>
int T,a,b;
int cmmdc(int a,int b)
{
int r;
while(b)
        {
        r=b;
        b=a%b; 
        a=r;
        }
return a;
}
int main()
{FILE *fin,*fout;
fin=fopen("euclid2.in","r");
fout=fopen("euclid2.out","w");
fscanf(fin,"%d",&T);
for(;T;T--)
           {
           fscanf(fin,"%d%d",&a,&b);
           fprintf(fout,"%d\n",cmmdc(a,b));
           }        
fclose(fin);fclose(fout);
return 0;
}
