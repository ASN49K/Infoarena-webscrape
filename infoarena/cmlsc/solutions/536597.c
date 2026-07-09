#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max(a, b) (a) > (b) ? (a) : (b)




int main(int argc, char **argv)
{
    int a[1024], b[1024], r[1024], m, n, p = 0, i, j, aux, nr = 0;
    
    FILE *in = fopen("cmlsc.in", "r");    
    FILE *out = fopen("cmlsc.out", "w");
    
    fscanf(in, "%d %d", &m, &n);
    for (i = 0; i < m; i++)
        fscanf(in, "%d", &a[i]);
    for (i = 0; i < n; i++)
        fscanf(in, "%d", &b[i]);
        
    int l[m][n];
    for (i = 0; i < m; i++)    
    for (j = 0; j < n; j++)
    {
        if(a[i] == b[j])
                aux = 1;
        else
            aux = 0;
        //aux = ((a[i] == b[j]) ? 1 : 0);
        if (i == 0 || j == 0)
           l[i][j] = aux;
        else
           l[i][j] = Max(l[i - 1][j - 1], Max(l[i][j - 1], l[i - 1][j])) + aux; 
        
        if (l[i][j] > nr)
        {
           r[p++] = a[i];
           nr = l[i][j];             
        }
    } 
    
    /*for (i = 0; i < m; i++)    
    {
        for (j = 0; j < n; j++)
            printf("%d ", l[i][j]);
        printf("\n");
    }*/
    
    fprintf(out, "%d \n", p);
    for (i = 0; i < p; i++)
        fprintf(out, "%d ", r[i]);   
    
    //fflush(stdin);
    //getchar();
    
    fclose(in);
    fclose(out);
    return 0;   
}
