#include <stdio.h>

using namespace std;

FILE*f=fopen("euclid2.in","r");
FILE*g=fopen("euclid2.out","w");

int main()
{
    int t,a,b,r;
    fscanf(f,"%d",&t);
    while (t){
        t--;
        fscanf(f,"%d%d",&a,&b);
        while (b){
            r=a%b;
            a=b;
            b=r;
        }
        fprintf(g,"%d\n",a);
    }
    fclose(f);
    fclose(g);
    return 0;
}
