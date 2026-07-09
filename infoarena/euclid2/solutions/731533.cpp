#include <cstdlib>
#include <stdio.h>
#include <fstream.h>

int cmmdc(int a, int b)
{
    int r;
    printf("Cel mai mare divizor comun dintre %d si %d ", a, b);
    while(r = a % b) {
            a = b;
            b = r;
            printf("\na = %d, b = %d\n",a,b);
    }
    
    printf(" este %d\n", b);
    return b;  
}

int main(int argc, char *argv[])
{
    FILE *citeste, *scrie;
    int a,b,n, dc;
    citeste = fopen("euclid2.in", "r");
    scrie = fopen("euclid2.out", "w");
    
    fscanf(citeste, "%d", &n);
   
    for(int i=0; i<n; i++)
    {
            fscanf(citeste, "%d", &a);
            fscanf(citeste, "%d", &b);
            dc = cmmdc(a,b);
            fprintf(scrie, "%d\n", dc);
    }
   
    system("PAUSE");
    return EXIT_SUCCESS;
}
