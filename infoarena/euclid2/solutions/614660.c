#include <stdio.h>
#include <stdlib.h>
int algoritm(int &x, int &y)
{int r;
if(x!=y)
while(y!=0)
{r=x%y;
x=y;
y=r;
}
return x;
}
int main()
{unsigned T, i;
int a,b;
FILE *f;
FILE *g;
f=fopen("euclid2.in","r");
g=fopen("ruclid2.out","w");
fscanf(f,"%u",&T);
for(i=1;i<=T;i++)
{fscanf(f, "%d %d", &a,&b);
a=algoritm(a,b);
fprintf(g,"%d\n",a);
}
fclose(f);
fclose(g);
return 0;
}