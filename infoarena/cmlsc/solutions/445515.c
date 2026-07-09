/*Fie v un vector cu N elemente. Se numeste subsir de lungime K al vectorului v un nou vector 
v' = (vi1, vi2, ... viK), cu i1 < i2 < ... < iK. De exemplu, vectorul v = (5 7 8 9 1 6) contine 
ca subsir sirurile (5 8 6) sau (7 8 1), dar nu contine subsirul (1 5). Se dau doi vectori A si 
B cu elemente numere naturale nenule.

Cerinta
Sa se determine subsirul de lungime maxima care apare atat in A cat si in B.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE *inp,*out;
int n,m;
char *a,*b,**nr;



void cit()
{
     int i,aux;
     inp=fopen("cmlsc.in","r");    
     fscanf(inp,"%d",&n);
     a=malloc(n*sizeof(char));
     fscanf(inp,"%d",&m);
     b=malloc(m*sizeof(char));
     for (i=0;i<n;i++)
     {
         fscanf(inp,"%d",&aux);
         a[i]=(char)aux;
     }
     for (i=0;i<m;i++)
     {
         fscanf(inp,"%d",&aux);
         b[i]=(char)aux;
     }
}



void afis()
{
     int i,j;
     for (i=0;i<n;i++)
     {
         for (j=0;j<m;j++)
             printf("%d ",nr[i][j]);    
         printf("\n");
     }    
}

int min(int a,int b)
{
    if(a<b) return a;
    return b;   
}

int main()
{
    
    int i,j,cont,p,in=0;
    
    cit();
    
    nr=calloc(n,sizeof(char *));
    for (i=0;i<n;i++)
        nr[i]=calloc(m,sizeof(char));    
        
    p=min(m,n);
    int c[p];    
    for(i=0;i<p;i++)
        c[i]=-1;
        
        
    i=0;
    while ((int)a[i]!=(int)b[0] && i<n)
    {
         nr[i][0]=0;       
         i++; 
    }
    cont=i;
    for (i=cont;i<n;i++)
        nr[i][0]=1;
    if(cont<n)
    {
         c[in]=(int)a[cont];
         in++;     
    }
    
    
    
    j=0;
    while((int)b[j]!=(int)a[0] && j<m)
    {
         nr[0][j]=0;                 
         j++; 
    }
    cont=j;
    for(j=cont;j<m;j++)
        nr[0][j]=1;
    if(cont<m)
    {
         c[in]=(int)b[cont];
         in++;     
    }    
    
    int incr;
    
    for (i=1;i<n;i++)
    {
        incr=0;
        for (j=1;j<m;j++)
        {
            if(nr[i-1][j-1]>=nr[i][j-1] && nr[i-1][j-1]>=nr[i-1][j])
               nr[i][j]=nr[i-1][j-1];
            if(nr[i][j-1]>=nr[i-1][j-1] && nr[i][j-1]>=nr[i-1][j])
               nr[i][j]=nr[i][j-1];
            if(nr[i-1][j]>=nr[i-1][j-1] && nr[i-1][j]>=nr[i][j-1])
               nr[i][j]=nr[i-1][j];
            
            if((int)a[i]==(int)b[j] && !incr)
            {
               nr[i][j]++;
               c[in]=(int)a[i];
               in++;
               incr=1;
            }
         }
    }
    
    out=fopen("cmlsc.out","w");
    fprintf(out,"%d \n",in);
    for (i=0;i<in;i++)
        fprintf(out,"%d ",c[i]);
    
    fclose(inp);
    fclose(out);
    
    //afis();
    //getchar();
    
    
    return 0;   
}
