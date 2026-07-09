#include <stdio.h>
#include <stdlib.h>
int euclid(int a,int b)
{
    if(!b) return a;
    return euclid(b,a%b);
}
void problema()
{
    FILE *f=fopen("euclid2.in","r");
    FILE *g=fopen("euclid2.out","w");
    int i,n,a,b;
    fscanf(f,"%d",&n);
    for(i=0;i<n;i++)
        {
            fscanf(f,"%d %d",&a,&b);
            fprintf(g,"%d\n",euclid(a,b));
        }
}
int main()
{
    problema();
    return 0;
}
