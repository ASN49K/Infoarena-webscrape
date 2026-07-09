#include<cstdio>

using namespace std;
FILE *f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");
int n,a,b,r;
int main()
{
int i;
fscanf(f,"%d",&n);
for(i=1;i<=n;i++)
{
    fscanf(f,"%d %d",&a,&b);
    while(a%b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    fprintf(g,"%d\n",b);
}
fclose(f);
fclose(g);
    return 0;
}
