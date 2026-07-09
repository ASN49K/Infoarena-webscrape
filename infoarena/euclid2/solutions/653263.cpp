#include <cstdio>
using namespace std;

int main ()
{int n,a,b,r;
FILE *f,*g;
f=fopen("euclid2.in","r");
g=fopen("euclid2.out","w");
fscanf(f,"%d",&n);
while(n)
{fscanf(f,"%d %d",&a,&b); n--;
while(b)
{r=a%b;
a=b;
b=r;
}

fprintf(g,"%d\n",a);
}

 fclose(f); fclose(g);
return 0;
}
