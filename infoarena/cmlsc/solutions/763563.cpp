#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <vector>

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
    
    int currPos = matrix[m+1][n+1];
    i=m+1,j=n+1;
    cout << currPos << endl;
    vector<int> seq;
    
   while(currPos)
   {

    
         if(matrix[i][j]==currPos&&
            matrix[i-1][j]<currPos&&
            matrix[i][j-1]<currPos&&
            matrix[i-1][j-1]<currPos)
          {         
                seq.push_back(matrix[i][0]);
                i--,j--;
                currPos--;                                                    
          }
         else
         {
             if(matrix[i-1][j]>matrix[i][j-1])
             {
                i--;                                  
             }
             else
             {
                j--;
             }
         }
                                  
                    
   }
     vector<int>::iterator it;
     for(it = seq.end()-1;it!=seq.begin();it--)
     {
        cout << *it << " ";
     }
     cout << *seq.begin();
    cin.close();
    cout.close();
    return 0;   
}
