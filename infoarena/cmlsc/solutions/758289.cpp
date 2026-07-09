#include <stdio.h>
int final[1050][1050];


int maxim(int a, int b)
{
    if (a > b)
       return a;
    else
        return b;
}

int main()
{
    FILE *f, *g;
    int n, m, v[1050], u[1050], rez[1050], iter = 0;
    
    f = fopen("cmlsc.in", "r");
    g = fopen("cmlsc.out", "w");
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &m);
    for(int i = 0; i < n; i++)
            fscanf(f, "%d", &v[i]);
    for(int i = 0; i < m; i++)
            fscanf(f, "%d", &u[i]);
    final[0][1] = final[1][0] = final[1][1] = 0;
    
    
    
    for(int i = 2; i < m + 2; i++)
    {
            final[0][i] = u[i - 2];
            final[1][i] = 0;
            }
            
    for(int i = 2; i < n + 2; i++)
    {
            final[i][0] = v[i - 2];
            final[i][1] = 0;
            }
            
            
    for(int i = 2 ; i < n + 2; i++)
            for(int j = 2; j < m + 2; j++)
                    {
                        if(final[i][0] == final[0][j])
                        {
                                       final[i][j] = final[i - 1][j - 1] + 1;
                                       
                                       }
                        else
                                       final[i][j] = maxim(final[i][j - 1], final[i - 1][j]);
                        
                        }
    fprintf(g, "%d\n", final[n + 1][m + 1]);
                        
    int k = n + 1, a;
    int l = m + 1;
    while(k >= 2 && l >= 2)
            {
                    a = maxim(final[k][l - 1], final[k - 1][l]);
                    if( a < final[k][l])
                    {
                                        rez[iter] = final[k][0];
                                        iter++;
                                        k--;
                                        l--;
                                        }
                    else
                                        if(a == final[k][l - 1])
                                             l--;
                                        else 
                                             k--;
                    }
            
            
            
            
    for(int i = iter - 1; i >= 0; i--)
    { 
            fprintf(g, "%d ", rez[i]);              
                         
                        }
    
            
            
            
            
     
   
            return 0;
        }
