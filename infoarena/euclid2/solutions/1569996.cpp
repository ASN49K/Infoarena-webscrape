#include<stdio.h>
int main ()
{
    int T,a,b,x,R;
    FILE *f,*g;
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    fscanf(f,"%d\n",&T);
    while (T>0)
    {  fscanf(f,"%d %d \n",&a,&b);
    if(a>b)
    {
        x=a;
        a=b;
        b=x;
    }
    R=a%b;
    while(R>0)
    {
        a=b;
        b=R;
        R=a%b;
    }
    fprintf(g,"%d\n",b);
    T--;
    }
    fclose(f);
    fclose(g);
    return 0;
}
