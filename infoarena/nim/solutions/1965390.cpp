#include <stdio.h>

using namespace std;

FILE*f=fopen("nim.in","r");
FILE*g=fopen("nim.out","w");

int main()
{
    int n,t,s,i,x;
    fscanf(f,"%d",&t);
    while (t>0){
        t--;
        fscanf(f,"%d",&n);
        s=0;
        for (i=1;i<=n;i++){
            fscanf(f,"%d",&x);
            s=s^x;
        }
        if (s) fprintf(g,"DA\n");
        else fprintf(g,"NU\n");
    }
    fclose(f);
    fclose(g);
    return 0;
}
