#include<cstdio>
using namespace std;
FILE *f,*g;
long r,a,b,n,i;
int main()
{f=fopen("euclid2.in","r");
g=fopen("euclid2.out","w");
fscanf(f,"%ld",&n);
for(i=1;i<=n;i++)
{fscanf(f,"%ld%ld",&a,&b);
r=a%b;
while(r!=0)
{a=b;
b=r;
r=a%b;
}
fprintf(g,"%d\n",b);
}
fclose(f);
fclose(g);
return 0;
}