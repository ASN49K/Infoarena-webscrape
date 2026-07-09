#include<stdio.h>
int main ()
{
    int T,a,b,x,y;
    FILE *f,*g;
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    fscanf(f,"%d\n",&T);
    while (T>0)
    {  fscanf(f,"%d %d \n",&a,&b);
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    fprintf(g,"%d\n",a);
    T=T-1;


}
fclose(f);
fclose(g);
return 0;

}
