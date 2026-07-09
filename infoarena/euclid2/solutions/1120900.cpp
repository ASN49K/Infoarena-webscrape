#include <cstdio>
using namespace std;
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");
int euclid(int a,int b)
{if (a<b) {int aux=a;a=b;b=aux;}
int r;
while (a%b!=0) {r=a%b;
                a=b;
                b=r;
                }
return b;
}
int main()
{int i,j,t,a,b;
fscanf(f,"%d",&t);
for (i=1;i<=t;i++) {fscanf(f,"%d %d",&a,&b);
                    fprintf(g,"%d\n",euclid(a,b));
                    }
return 0;
}
