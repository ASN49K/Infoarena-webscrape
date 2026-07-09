#include <fstream>
#include <iostream>

using namespace std;

fstream f,g;
int longest;
short matrix[1027][1027]; 
int m,n;
int i,j;


int main()
{
    f.open("cmlsc.in",fstream::in);
    g.open("cmlsc.out",fstream::out);
    
    f >> m >> n;
    for(i=2;i<m+2;i++)
       f >> matrix[i][0];
    for(i=2;i<n+2;i++)
       f >> matrix[0][i];
       
    for(i=2;i<m+2;i++)
      for(j=2;j<n+2;j++)
        {
         if(matrix[i][0]==matrix[0][j])
            {
              matrix[i][j] = (matrix[i-1][j-1]>matrix[i][j-1]?
               (matrix[i-1][j-1]>matrix[i-1][j]?matrix[i-1][j-1]:matrix[i-1][j])
                 :
               (matrix[i][j-1]>matrix[i-1][j]?matrix[i][j-1]:matrix[i-1][j])) + 1;
             if(matrix[i][j]>longest)
                longest = matrix[i][j];   
             }           
         else
             matrix[i][j] = (matrix[i-1][j-1]>matrix[i][j-1]?matrix[i-1][j-1]:matrix[i][j-1]);   
       }
    
    int sol[1024];
    int k=0;
    
     for(i=m+1;i>1;i--)
      for(j=n+1;j>1;j--)
           if(matrix[i][j] == longest&& matrix[i][j]>matrix[i][j-1]&& matrix[i][j]>matrix[i-1][j-1])
           {
              sol[k++] = matrix[0][j];
              longest--;             
           }               
    
   
    for(i=k-1;i>=0;i--)
      g << sol[i] << " ";
    f.close();
    g.close();    
    
    return 0;
}
