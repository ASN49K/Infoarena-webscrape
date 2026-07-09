#include <fstream>

using namespace std;

fstream f;
fstream g;

int lungime;
int m,n;
int i,j;
int a[1028][1028];

int ax[3];

int Max(int a,int b)
{
   if(a>b)
     return a;
  return b;
}



int main()
{
    f.open("cmlsc.in",fstream::in);
    f >> m >> n;
    for(i=2;i<m+2;i++)
       f >> a[0][i]; 
    for(i=2;i<n+2;i++)
      f>> a[i][0];       
    f.close();

    
    g.open("cmlsc.out",fstream::out);
    for(i=2;i<n+2;i++)
      for(j=2;j<m+2;j++)
      {
          if(a[0][j]==a[i][0])
             a[i][j] = a[i-1][j-1]+1;
          else   
             a[i][j] = Max(a[i-1][j],a[i][j-1]);
          if( ax[0] <= a[i][j])
            {
                 ax[0]=a[i][j];
                 ax[1]=i;
                 ax[2]=j;               
              }
        }
       g <<  ax[0] << "\n";
    int vector[1025];
    int k=0;
    
     for(i=0;i<n+2;i++)
     {
         for(j=0;j<m+2;j++)
            g << a[i][j] << " ";
          g << "\n";                 
                        
     }
      
      int flag=0;
      for(i=n+1;i>1;i--)
        if(flag) break;
        else  
          for(j=m+1;j>1;j--){
            if(a[i][j]==ax[0]&&a[i][j-1]==a[i-1][j]&&a[i][j-1]!=a[i][j])
            {
      
              vector[k++]=a[0][j];
              ax[0]--;  
             if(!ax[0])
               flag=1;
             if(flag) break;
               break;                 
            }
            }
       for(i=k-1;i>=0;i--)
         g << vector[i] << " ";
    g.close();    
    return 0;
    
}
