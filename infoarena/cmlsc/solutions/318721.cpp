#include <fstream>
#include <iostream>

using namespace std;

fstream f,g;
int longest;
short matrix[1027][1027]; 
int m,n;
int i,j;


int getmax()
{
    int i,j;
    int max=0;
    int x,y;

    for(i=2;i<m+2;i++)
      for(j=2;j<n+2;j++)
        {
         if(max<matrix[i][j])
        {
            max=matrix[i][j];
            x=i;
            y=j;                    
        }
         if(max&&matrix[i][j]==0)
           return max;
        }    
      return max;
}

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
         if(matrix[i][0]==matrix[0][j])
            {
              matrix[i][j] = matrix[i-1][j-1]+1;            }          
         else
           matrix[i][j] = getmax();
    
    int sol[1024];
    int k=0;
    
    
    longest=0;
     for(i=2;i<m+2;i++)
      for(j=2;j<n+2;j++)
           if(matrix[i][0]==matrix[0][j]&&longest<matrix[i][j])
              {
              sol[k++] = matrix[0][j];
              longest++;             
           }               
    
   g << longest << "\n";
    
    for(i=0;i<k;i++)
      g << sol[i] << " ";
    f.close();
    g.close();    
    
    return 0;
}
