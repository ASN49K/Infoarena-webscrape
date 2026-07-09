#include<cstdio>
int nN;
int main()
{
FILE *fin=fopen("euclid2.in", "r");
FILE *fout=fopen("euclid2.out", "w");
fscanf(fin,"%d", &nN);
for (int i=1;i<=nN;i++)
{
int a,b;
fscanf(fin,"%d %d", &a, &b);
while (a!=0 && b!=0)
if (a>b)
a=a%b;
else
b=b%a;
fprintf(fout, "%d\n", a>b?a :b);
}
return 0;
}

