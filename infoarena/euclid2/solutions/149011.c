#include <stdio.h>
#define input "euclid2.in"
#define output "euclid2.out"
long a,b;
void read()
{
 FILE *fin;
 fin=fopen(input,"r");
 fscanf(fin,"%ld %ld",&a,&b);
 fclose(fin);
}
long cmmdc(long a,long b)
{
 if (a%b) return cmmdc(b,a%b);
    else return b;
}
void write()
{
 FILE *fout=fopen(output,"w");
 fprintf(fout,"%ld",cmmdc(a,b));
 fclose(fout);
}
int main()
{
 read();
 write();
 return 0;
}