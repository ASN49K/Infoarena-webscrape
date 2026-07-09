#include <stdio.h>
#include <stdlib.h>

int euclid(int a,int b)
{
    int r=a%b;
    if (r==0)
        return b;
    else return euclid(b,r);

}

int main()
{
    FILE *f=fopen("euclid2.in","r");
    FILE *g=fopen("euclid2.out","w");
    if(f==NULL)
    {
        perror("Eroare\n");
    }

    int T;
    fscanf(f,"%d",&T);
    int a,b;
    int i;
    for(i=0;i<T;i++)
    {
        fscanf(f,"%d%d",&a,&b);
        fprintf(g,"%d\n",euclid(a,b));
    }
    fclose(f);
    fclose(g);
    return 0;
}
