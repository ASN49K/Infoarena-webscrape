#include<fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int m, n, A[1024],B[1024], lcs[1024][1024], i, j, sol[1024], contor;  
int max(int a, int b)
{
 if(a>b) return a;
 else return b;   
}
int main()
{
    cin>>m>>n;
    for(i=1;i<=m;i++)
         cin>>A[i];
    for(j=1;j<=n;j++)
         cin>>B[j];
    for(i=1;i<=m;i++)
       for(j=1;j<=n;j++)
           if(A[i]==B[j])
               lcs[i][j]=lcs[i-1][j-1]+1;
           else lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
           
           cout<<lcs[m][n]<<"\n";
i = m; j = n;         
         while( i && j ) 
         { 
                if( A[i] == B[j] )               
                {   contor++;sol[contor] = A[i], --i, --j;  }
            
                else
                                  if( lcs[i][j-1] < lcs[i-1][j] ) 
                                                   i--; 
                                  else 
                                                   j--;
         } 
        
for(i = contor; i >= 1; i--) 
            
cout << sol[i] << " "; 


    return 0;
}
