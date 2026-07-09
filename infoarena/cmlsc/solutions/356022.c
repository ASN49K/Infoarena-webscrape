# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <math.h>

int Reductibila(int p, int q, int *r)
// r este parametru transmis prin referinta;
// functia va fi apelata cu Reductibila(p,q,&r);
{
    int m;
    
    if (p>q)
       m=p;
    else 
       m=q;
       
    for (int i=2 ; i<m ; i++)
    {
         if (p%i==0 && q%i==0)
         {
              *r=i;
              return 0;
         }
    }
    return 1;
}

int main()
{
     FILE *f;
     char nume[21];
     int n,nr=1,r;
     
     printf("Introduceti numele fisierului: ");
     scanf("%s",&nume);
     
     f = fopen(nume,"rt");
     
     if (!f)
        printf("\nNo such file!");
     else
     {
         fscanf(f,"%i",&n);
         fclose(f);
         
         for (int i = 1 ; i<=n ; i++)
         {
             for (int j = 1 ; j<=n ; j++)
             {
                  if (i != j)
                  {
                      nr++;
                      printf("+%i/%i ",i,j);
                      
                      if ((i%j==0 || j%i==0) && (i!=1 && j!=1) || (Reductibila(i,j,&r)==0))
                      {
                           nr--;
                           printf("-%i/%i ",i,j);
                      }
                  }
             }
         }
         printf("\nNumarul de fractii ireductibile ce se pot forma este: %i\n",nr);
     }
     
     getch();
     return 0;
}
