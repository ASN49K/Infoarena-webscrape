//LCS complexity n*m programare dinamica
// backtrakingul ar fi exponential

#include <stdio.h>
#include <stdlib.h>
#define Nmax 1024
int D[Nmax][Nmax];  //e initializat cu 0

void citire(int a[], int b[],int *n, int *m)
{
    FILE *f;
    f=fopen("cmlsc.in","r");


    fscanf(f,"%d %d",n,m);


    int i;
    for (i=1; i<=*n; i++)
           fscanf(f,"%d",&a[i]);


    for (i=1; i<=*m; i++)
       fscanf(f,"%d",&b[i]);


    fclose(f);
}


void LCS(int a[],int b[],int n,int m)
{
    int i,j; int max[Nmax],k;

    freopen("cmlsc.out", "w", stdout);
    for (i=1; i<=n; i++)
       {
           for (j=1; j<=m; j++)
             if (a[i]==b[j])
                  D[i][j]=D[i-1][j-1]+1;
                  else
                  D[i][j]=(D[i][j-1] > D[i-1][j]) ? D[i][j-1] :  D[i-1][j];

       }

  /*  printf("Afisare matrice:\n");
    for (i=0; i<=n; i++)
       {
           for (j=0; j<=m; j++)
               printf("%d ",D[i][j]);
           printf("\n");
       }
   */
    //Decodificare matrice

    i=n; j=m; k=0;

    while (i>0 && j>0)
       if (a[i]==b[j])
       {
           max[k]=a[i];
           k++;
           i--;
           j--;

       }
          else if (D[i-1][j]<D[i][j-1])
               j--;
               else
               i--;

   printf("%d\n",k);
   for (i=k-1; i>=0; i--)
       printf("%d ",max[i]);



}

int main()
{
    int a[Nmax], b[Nmax],n,m;

    citire(a,b,&n,&m);
    LCS(a,b,n,m);



    return 0;
}
