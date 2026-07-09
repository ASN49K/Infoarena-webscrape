#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *f,*g;
    int a,b,*v,*w,i,j,ok,*v1,*w1,i1,j1,*v2,*w2;
    f=fopen("cmlsc.in","r");
    g=fopen("cmlsc.out","w");
    fscanf(f,"%d",&a);
    fscanf(f,"%d",&b);
    v=(int*)malloc(a*sizeof(int));
    v1=(int*)malloc(a*sizeof(int));
    v2=(int*)malloc(a*sizeof(int));
    w=(int*)malloc(b*sizeof(int));
    w1=(int*)malloc(b*sizeof(int));
    w2=(int*)malloc(b*sizeof(int));
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

for(i=0;i<ki;i++)
    printf("%d  ",v1[i]);
printf("\n");
for(j=0;j<kj;j++)
    printf("%d  ",w1[j]);

// pana aici pare bine

printf("\nki=%d, kj=%d\n",ki,kj);    
int max=0,val=0,hi=0,po,aux=0,O[50][50],M=0;
int qu;
for(i=0;i<ki;i++)
    for(j=0;j<ki;j++)
        if(v1[i]==w1[j])
            qu=1;
if(qu==0 || ki==0 || kj==0) val=1;


for(po=0;po<ki;po++)
{
    aux=0;
for(i=po;i<ki;i++)
    for(j=i;j<kj;j++)
        {
            if(v1[i]==w1[j])
            {
                 aux++;
                 O[hi][po]=v1[i];
                 hi++;
                // i=j+1;
                 break;
            }
        }

printf("\naux=%d\n",aux);
if(max<aux)
{max=aux;M=po;
printf("max=%d\n",max);}
}

printf("lungime subsir: %d , M=%d\n",max,M);

if(val==1){   // daca nu avem nr comune
    fprintf(g,"%d",0); printf("\nRezultat: %d\n",0);
    return;
}

fprintf(g,"%d\n",max); printf("\nRezultat: %d\n",max);   // daca exista un sir comun de lungime >=1
for(i=0;i<max-1;i++)
    {
    fprintf(g,"%d ",O[i][M]); printf("%d ",O[i][M]);
    }
    fprintf(g,"%d",O[max-1][M]); printf("%d",O[max-1][M]);


//    printf("%d ",v[i]);
//printf("\n");
//for(j=0;j<b-1;j++)
//    printf("%d ",w[j]);
//    printf("%d ",w[b-1]);

    free(v);
    free(w);
    free(v1);
    free(w1);
    free(w2);
    free(v2);
    fclose(f);
    fclose(g);
}
