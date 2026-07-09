#include<fstream>
using namespace std;
int i,j,n,m,a[1025],b[1025],sol[1025][1025],drum[1025];

int main(void) {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>n>>m;
    for (i=1; i<=n; ++i) fin>>a[i];
    for (i=1; i<=m; ++i) fin>>b[i];
    
    for (i=1; i<=n; ++i)
     for (j=1; j<=m; ++j) 
     if (a[i]==b[j]) 
               sol[i][j]=1+sol[i-1][j-1];
           else 
               sol[i][j]=max( sol[i][j-1],sol[i-1][j] );
               
    fout<<sol[n][m]<<"\n";
    
    i=n; j=m; int l=sol[n][m];
    
    while (i>=1&&j>=1) {
          if (a[i]==b[j]) { 
                           drum[l]=a[i]; --l; --i; --j; 
                           }
          else 
              if (sol[i][j]==sol[i-1][j]) --i;
          else 
              if (sol[i][j]==sol[i][j-1]) --j;
            }
            
     for (i=1; i<=sol[n][m]; ++i)
                                fout<<drum[i]<<" ";
    
    return(0);
}
