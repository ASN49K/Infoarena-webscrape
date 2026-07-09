#include <cstdio>
using namespace std;
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");
int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
int main()
{
    int a,b;
    int N;
    fscanf(f,"%d",&N);
    for(int i=1;i<=N;i++)
    {
        fscanf(f,"%d %d",&a,&b);
        fprintf(g,"%d\n",gcd(a,b));
    }
    fclose(f);
    fclose(g);
    return 0;
}
