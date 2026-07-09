#include <cstdio>

using namespace std;
int euclid(int a,int b)
{
int r;
 while(b != 0)
{
	r = a % b;
	a = b;
	b = r;
}
return a;

}
int main()
{ int p,n;
    FILE *f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");
    fscanf(f,"%d",&n);
    int x1,x2;
    for(int i=1;i<=n;i++)
    {
        fscanf(f,"%d%d",&x1,&x2);
        p=euclid(x1,x2);
        fprintf(g,"%d",p); fprintf(g,"\n");
    }

    return 0;
}
