#include <iostream>
#include <stdio.h>
using namespace std;
FILE *f,*g;
int cmmdc(int a, int b)
{   int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void solve()
{   int n,a,b;
    fscanf(f,"%d",&n);
    for(int i=1; i<=n; i++)
    {
        fscanf(f,"%d %d",&a,&b);
        fprintf(g,"%d\n",cmmdc(a,b));
    }
}
int main()
{
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    //read();
    solve();
    //write();
    fclose(f);
    fclose(g);
    return 0;
}
