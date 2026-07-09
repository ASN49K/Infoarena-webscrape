#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>

using namespace std;

int m,n;
int matrix[1026][1026];

int main(void)
{
    fstream cin;
    fstream cout;
    cin.open("cmlsc.in",fstream::in);
    cout.open("cmlsc.out",fstream::out);
    memset(matrix,0,sizeof(matrix));
          
    cin >> m >> n;
    int i,j;
    for(i=2;i<=m+1;i++)
         cin >> matrix[i][0];

    for(i=2;i<=n+1;i++)  
       cin >> matrix[0][i];
    
    for(i=2;i<=m+1;i++)
       for(j=2;j<=n+1;j++)
       {
           if(matrix[i][0]==matrix[0][j])
           {
               matrix[i][j] = matrix[i-1][j-1]+1;                          
           }
           else
           {
               matrix[i][j] = max(matrix[i-1][j],matrix[i][j-1]);
           }                
       }  
    
    int currPos = 1;
    cout << matrix[m+1][n+1] << endl;
    for(i=2;i<=m+1;i++)
       for(j=2;j<=n+1;j++)
          if(matrix[i][j]==currPos)
          {
              cout << matrix[i][0] << " ";    
              currPos++;                     
          }     
    cin.close();
    cout.close();
    return 0;   
}
