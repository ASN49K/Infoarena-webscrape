#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *f,*g;
    int a,b,*v,*w,i,j,ok,*v1,*w1;
    f=fopen("cmlsc.in","r");
    g=fopen("cmlsc.out","w");
    fscanf(f,"%d",&a);
    fscanf(f,"%d",&b);
    v=(int*)malloc(a*sizeof(int));
    v1=(int*)malloc(a*sizeof(int));
    w=(int*)malloc(b*sizeof(int));
    w1=(int*)malloc(b*sizeof(int));
    for(i=0;i<a;i++)
        fscanf(f,"%d",&v[i]);
    for(i=0;i<b;i++)
        fscanf(f,"%d",&w[i]);
for(i=0;i<a;i++)
{
    ok=0;
    for(j=0;j<b;j++)
        if(v[i]==w[j])
        {
            ok=1;
        }
    if(ok==0)
        v[i]=-1;
}
for(j=0;j<b;j++)
{
    ok=0;
    for(i=0;i<a;i++)
        if(v[i]==w[j])
        {
            ok=1;
        }
    if(ok==0)
        w[j]=-1;
}

int ki=0,kj=0;
for(i=0;i<a;i++)
    if(v[i]>=0)
    {
        v1[ki]=v[i];
        ki++;
    }

for(j=0;j<b;j++)
    if(w[j]>=0)
    {
        w1[kj]=w[j];
        kj++;
    }

fprintf(g,"%d\n",kj);
for(i=0;i<kj;i++)
    fprintf(g,"%d ",w1[i]);

    printf("%d ",v[i]);
printf("\n");
for(j=0;j<b;j++)
    printf("%d ",w[j]);


    free(v);
    free(w);
    free(v1);
    free(w1);
    fclose(f);
    fclose(g);
}
