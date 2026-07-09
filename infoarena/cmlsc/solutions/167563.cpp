#include <iostream.h>
#include <stdio.h>

int x[1026],y[1026];
int max,a,b;
int n[1026][1026];  
int sol[1026];
     
int main(void)
{  
  freopen("cmlsc.in", "r", stdin);  
  
  int i,j;
  
  scanf("%d", &a);
  scanf("%d", &b);  
  
  a++;b++;   
  
  for (i=1; i!=a; ++i)  
    {  
        scanf("%d", &x[i]);  
    }          
  
  x[0] = -1;  
    
  for (i=1; i!=b; ++i)  
    {  
        scanf("%d", &y[i]);  
    }          
  fclose(stdin);

  
  for (int i=1;i<=a;i++)
    for (int j=1;j<=b;j++){
        if (x[i-1] == y[j-1])
          n[i][j] = n[i-1][j-1] + 1;
        else
          if (n[i][j-1] > n[i-1][j])  
            n[i][j] = n[i][j-1];
        else n[i][j] = n[i-1][j];    
        }
                               
  for (i = a,j = b;n[i][j];)
    if (x[i-1] == y[j-1]){
      sol[++max] = x[i-1];
      i--;j--;
      }
    else
      if (n[i][j-1] > n[i-1][j]) 
      j--;
    else
      i--;      
                                    
  freopen("cmlsc.out", "w", stdout);   
  printf("%d\n", max);
  for (i=max;i;i--){
   printf("%d\ ", sol[i]);
   }
  fclose(stdout);
    
  return 0;  
}
