#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//Sume partiale:N numere, K query-uri:sum(i,j)
void sume_partiale_vector(){
    int n,k,i,first,last,m=-1;
    FILE *f=fopen("sumepartiale.txt", "r");
    fscanf(f,"%d%d", &n, &k);
    int *v1=(int*)malloc(sizeof(int)*n);
    int *v2=(int*)malloc(sizeof(int)*n);
    int *v3=(int*)malloc(sizeof(int)*k);
    for(i=0;i<n;i++)
        fscanf(f,"%d", &v1[i]);
    v2[0]=v1[0];
    for(i=1;i<n;i++)
        v2[i]=v2[i-1]+v1[i];
    for(i=0;i<k;i++){
        fscanf(f,"%d%d", &first,&last);
        if(first>last){
            int aux=first;
            first=last;
            last=aux;
        }
        if(first)
            v3[++m]=v2[last]-v2[first-1];
            else v3[++m]=v2[last];
    }
    for(i=0;i<k;i++)
        printf("%d\n", v3[i]);
}

int max(int a,int b,int c)
{
    if(a>=b && a>=c)
        return a;
        else if(b>=a && b>=c)
            return b;
            else return c;
}
//Sume partiale:NxN numere, K query-uri:sum((l1,c1),(l2,c2))
void sume_partiale_matrice(){
    int i,j,n,m,k,c1,c2,l1,l2,m1[101][101],m2[101][101],g,aux;
    FILE *f=fopen("sumepartiale^2.txt", "r");
    fscanf(f,"%d%d%d", &n, &m, &k);
    int *sol=(int*)malloc(sizeof(int)*k);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            fscanf(f,"%d", &m1[i][j]);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            printf("%d ", m1[i][j]);
        printf("\n");
    }
    m2[0][0]=m1[0][0];
    for(i=1;i<n;i++)
        m2[i][0]=m2[i-1][0]+m1[i][0];
    for(j=1;j<m;j++)
        m2[0][j]=m2[0][j-1]+m1[0][j];
    for(i=1;i<n;i++)
        for(j=1;j<m;j++)
            m2[i][j]=m1[i][j]+m2[i-1][j]+m2[i][j-1]-m2[i-1][j-1];
    for(g=0;g<k;g++){
        fscanf(f,"%d%d%d%d", &l1, &c1, &l2, &c2);
        if(c1>c2){
            aux=c1;
            c1=c2;
            c2=aux;
        }
        if(l1>l2){
            aux=l1;
            l1=l2;
            l2=aux;
        }
        if(l1==0 && c1==0)
            sol[g]=m2[l2][c2];
            else if(l1!=0 && c1==0)
                sol[g]=m2[l2][c2]-m2[l1-1][c2];
            else if(l1==0 && c2!=0)
                sol[g]=m2[l2][c2]-m2[l2][c1-1];
            else sol[g]=m2[l2][c2]-m2[l1-1][c2]-m2[l2][c1-1]+m2[l1-1][c1-1];
    }
    for(g=0;g<k;g++)
        printf("%d ", sol[g]);
}
void  subsecventa_suma_maxima()
{
    int sum=0,i,max=0,n;
    FILE *f=fopen("subsecventa.txt", "r");
    fscanf(f,"%d", &n);
    int *x=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        fscanf(f,"%d", &x[i]);
    for(i=0;i<n;i++)
        printf("%d ", x[i]);
    printf("\n");
    for(i=0;i<n;i++){
        if(max<sum)
            max=sum;
        sum+=x[i];
        if(sum<0)
            sum=0;
    }
    printf("%d", max);
}

void siruri()
{
    FILE *f=fopen("cmlsc.in", "r");
    FILE *g=fopen("cmlsc.out", "w");
    int i,n1,n2,s1[1025],s2[1025],j,x,ok,sol[1025];
    short int D[1024][1024];
    fscanf(f,"%d %d", &n1, &n2);
    for(i=0;i<n1;i++)
        fscanf(f,"%d", &s1[i]);
    for(i=0;i<n2;i++)
        fscanf(f,"%d", &s2[i]);
    i=ok=0;
    while(i<n2 && !ok)
    {
        if(s1[0]==s2[i])
        {
            ok=1;
            for(j=i;j<n2;j++)
                D[0][j]=1;
        }
        i++;
    }
    i=ok=0;
    while(i<n1 && !ok)
    {
        if(s1[i]==s2[0])
        {
            ok=1;
            for(j=i;j<n1;j++)
                D[j][0]=1;
        }
        i++;
    }
    for(i=1;i<n1;i++)
        for(j=1;j<n2;j++)
        {
            if(s1[i]==s2[j])
                x=1;
                else x=0;
            x+=D[i-1][j-1];
            D[i][j]=max(D[i-1][j],D[i][j-1],x);
        }
    i=n1-1;
    j=n2-1;
    int size=D[i][j];
    fprintf(g,"%d\n", size);
    x=size;
    while(x)
    {
        ok=0;
        while(!ok)
            if(D[i][j-1]==D[i][j])
                j--;
                else ok=1;
        ok=0;
        while(!ok)
            if(D[i-1][j]==D[i][j])
                i--;
                else ok=1;
        sol[x-1]=s2[j];
        j--;
        x--;
    }
    for(i=0;i<size;i++)
        fprintf(g,"%d ",sol[i]);

}
void subsir_crescator_maximal()
{
    FILE *f = fopen("scmax.in", "r");
    FILE *g = fopen("scmax.out", "w");
    int n, i, pos_max=1 ,j ,ok;
    fscanf(f, "%d", &n);
    int x[100001], d[100001], p[100001], sol[100001],poz;
    for(i = 0; i < n; i++)
        fscanf(f,"%d ", &x[i]);
    d[0] = -1;
    p[0] = -1;
    d[1] = 0;
    for(i = 1; i < n ; i++)
    {
        ok = 0;
        j=1;
        while(j <= pos_max && !ok)
            if(x[i]<=x[d[j]])
            {
                ok=1;
                d[j]=i;
            }
            else j++;
        if(!ok)
        {
            pos_max++;
            d[pos_max]=i;
        }
        p[i]=d[j-1];
    }
    poz=d[pos_max];
    sol[0]=x[poz];
    i=0;
    while(p[poz]!=-1)
    {
        i++;
        poz=p[poz];
        sol[i]=x[poz];
    }
    /*printf("%d\n", pos_max);
    for(i=1;i<=pos_max;i++)
        printf("%d " ,d[i]);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d ", p[i]);*/
    fprintf(g,"%d\n", pos_max);
    for(i=pos_max-1;i>=0;i--)
        fprintf(g,"%d ", sol[i]);
}

void deck()
{
    int n, k, x[10001], i=1, deck[100001],first=0,last=0, j,ok;
    FILE *f = fopen("deck.in", "r");
    FILE *g = fopen("deck.out", "w");
    fscanf(f ,"%d%d" , &n, &k);
    for(i = 0 ; i<n ; i++)
        fscanf(f,"%d", &x[i]);
    deck[first]=0;
    for(i = 1 ; i<k ;i++)
    {
    ok=0;
    while(last>=first && !ok)
        if(x[i]>=x[deck[last]])
            last--;
            else ok=1;
    last++;
    deck[last]=i;
    }
    for(i=k;i<n;i++)
    {
        printf("%d ", x[deck[first]]);
        if(deck[first]+k<=i && first!=last)
            first++;
        ok=0;
        while(last>=first && !ok)
            if(x[i]>=x[deck[last]])
                last--;
                else ok=1;
        last++;
        deck[last]=i;
    }
    printf("%d ", x[deck[first]]);
}

int main(){
    siruri();
    return 0;
}
