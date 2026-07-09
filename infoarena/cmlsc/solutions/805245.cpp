# include <iostream>
# include <stdio.h>
# include <algorithm>
//# include <conio.h>
int matrix[1024][1024];
 FILE *f, *g;

 void clsc (int n, int m, int *x, int *y) {
      int i, j, v[1000], k;
      for (i = 0; i < n; i++) {
          for (j = 0; j < m; j++) {
              if (x[i] == y[j]) {
                 matrix[i+1][j+1] = matrix[i][j] + 1;
                 }
                  else {
                     matrix[i+1][j+1] = std::max(matrix[i+1][j], matrix[i][j+1]);  
                       }
          } 
          }
          /*
          for (i = 1; i <= n ; i++) {
              for (j = 1; j <= m; j++)
                  std::cout << matrix[i][j] << " ";
                  std::cout << std::endl;
                  }*/
              fprintf(g,"%d\n", matrix[n][m]);
            i = n; 
            j = m; 
            k =0;
             while (i>1 && j>1) {
                  if (x[i-1] == y[j-1]) {
                           i--; 
                           j--;
                           v[k] = x[i];
                           //std::cout << x[i] << " " << y[j] << std::endl;
                           k++;
                           }
                      else {
                      if (matrix[i-1][j] > matrix[i][j-1])
                        i--; 
                        else
                        j--;
                           }
                        }
                  for (i = matrix[n][m] -1; i >= 0; i--)
                   fprintf(g, "%d ", v[i]);
                   }
                     
int main () {
   
    f = fopen("cmlsc.in", "r");
    g = fopen("cmlsc.out", "w");
    int n, m, i;
    fscanf(f, "%d %d", &n, &m);
    int x[n], y[m];
    for (i = 0; i < n; i++)
        fscanf(f, "%d", x+i);
    for (i = 0; i < m; i++)
        fscanf(f, "%d", y+i);
        clsc(n, m, x, y);
        //getch();
    return 0;
}
