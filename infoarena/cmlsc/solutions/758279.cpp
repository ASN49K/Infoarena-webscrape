#include <stdio.h>

int main()
{
    FILE *f, *g;
    int n, m, v[1050], u[1050], subsir = 0, subsir_max = 0, nivel = 0, final[10000], poz_ultim = 0, ceva = 0;
    f = fopen("cmlsc.in", "r");
    g = fopen("cmlsc.out", "w");
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &m);
    for(int i = 0; i < n; i++)
            fscanf(f, "%d", &v[i]);
    for(int i = 0; i < m; i++)
            fscanf(f, "%d", &u[i]);
          /*  for(int i = 0; i < n; i++)
            fprintf(g, "%d", v[i]);
            for(int i = 0; i < m; i++)
            fprintf(g, "%d", u[i]);*/
    
    
   for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                    {
                        if(ceva > 0)
                        {
                                j = poz_ultim; 
                                ceva = 0;
                                }   
                        if(v[i] == u[j])
                                {
                                        subsir++;
                                        final[nivel] = v[i];
                                        nivel++;
                                        poz_ultim = j;
                                        ceva = 1;
                                        break;
                                        } 
                        }    
    fprintf(g, "%d\n", subsir);
    for(int i = 0; i < nivel; i++)
            fprintf(g, "%d ", final[i]);
            return 0;
        }
