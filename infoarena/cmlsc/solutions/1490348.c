#include <stdio.h>
#include <stdlib.h>

int **info1;
int **info2;
int *sol;
int l1,l2,l;

void citire()
{
    FILE *f=fopen("cmlsc.in","r");
    int i,aux;

    fscanf(f,"%d%d",&l1,&l2);

    info1=(int**)malloc(sizeof(int*));
    *info1=(int*)malloc(l1*sizeof(int));

    info2=(int**)malloc(sizeof(int*));
    *info2=(int*)malloc(l2*sizeof(int));

    for (i=0;i<l1;i++)
        fscanf(f,"%d",*info1+i);
    for (i=0;i<l2;i++)
        fscanf(f,"%d",*info2+i);
    if (l1<l2)
    {
        int **aux_v;
        aux_v=info1;
        info1=info2;
        info2=aux_v;
        aux=l1;
        l1=l2;
        l2=aux;
    }

    fclose(f);
}

int predicat(const void* a,const void *b)
{
    return ((*(int*)a)-(*(int*)b));
}

void rezolvare()
{
    int i,j,poz;

    sol=(int*)malloc(l1*sizeof(int));
    for (i=0,poz=0;i<l1;i++)
    {
        for (j=poz;j<l2;j++)
            if(*(*info1+i)==*(*info2+j))
            {
                sol[l]=*(*info1+i);
                l++;
                poz=j;
                break;
            }
    }
}

void afisare()
{
    FILE *g=fopen("cmlsc.out","w");
    int i;

    fprintf(g,"%d\n",l);

    for (i=0;i<l;i++)
        fprintf(g,"%d ",sol[i]);
    fclose(g);
}

int main()
{
    citire();
    //qsort(*info2,l2,sizeof(int),predicat);
    rezolvare();
    afisare();
    return 0;
}
