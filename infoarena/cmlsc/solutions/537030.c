#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max(a, b) (a) > (b) ? (a) : (b)




int main(int argc, char **argv)
{
    int a[1025], b[1025], r[1025], m, n, i, j, lmax;
    
    FILE *in = fopen("cmlsc.in", "r");    
    FILE *out = fopen("cmlsc.out", "w");
    
    fscanf(in, "%d %d", &m, &n);
    //printf("%d  %d\n", m , n);
    for (i = 1; i <= m; i++)
        fscanf(in, "%d", &a[i]);
    for (i = 1; i <= n; i++)
        fscanf(in, "%d", &b[i]);
        
        
    int l[m+1][n+1];
    
    for (i = 0; i <= m; i++)
        l[i][0] = 0;    
    for (j = 0; j <= n; j++)
        l[0][j] = 0;
    
    for (i = 1; i <= m; i++)    
    for (j = 1; j <= n; j++)
    {
        if(a[i] == b[j])
             l[i][j] = l[i - 1][j - 1] + 1;
        else 
             l[i][j] = Max(l[i - 1][j], l[i][j - 1]); 
    } 
    lmax = l[m][n];
    i = lmax - 1;
    
    while(m > 0 && n > 0 && l[m][n] > 0)
    {
         if (l[m][n] == l[m - 1][n])
              m--;
         else if(l[m][n] == l[m][n - 1])
              n--;  
         else
         {
              r[i] = a[m];
              i --;
              m--;
              n--;
         }
    }
    
    
    fprintf(out, "%d \n", lmax);
    for (i = 0; i < lmax; i++)
        fprintf(out, "%d ", r[i]);   
    
    //fflush(stdin);
    //getchar();
    
    fclose(in);
    fclose(out);
    return 0;   
}
