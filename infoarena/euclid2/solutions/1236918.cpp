#include<stdio.h>
using namespace std;
int main()
{
    FILE*f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");
    int n,a,b,aux;
    fscanf(f,"%d",&n);
    for(;n>0;n--)
    {
        fscanf(f,"%d%d",&a,&b);
        while(b)
        {
            aux=a;
            a=b;
            b=aux%b;
        }
        fprintf(g,"%d\n",a);
    }
    return 0;
}
