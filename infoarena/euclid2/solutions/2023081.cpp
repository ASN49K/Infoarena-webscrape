#include <cstdio>

using namespace std;

FILE * f=fopen("euclid2.in","r");
FILE * g=fopen("euclid2.out","w");
int n,x,y;
int euclid (int a, int b)
{
    while(b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    fscanf(f,"%d",&n);
    while(n)
    {
        fscanf(f,"%d%d",&x,&y);
        fprintf(g,"%d\n",euclid(x,y));
        n--;
    }
    return 0;
}
