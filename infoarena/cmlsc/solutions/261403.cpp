#include <fstream>

using namespace std;

fstream f;
fstream g;

int lungime;
int m,n;
int i,j;
int a[1027][1027];

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
          if( ax[0]<a[i][j])
            {
                 ax[0]=a[i][j];
                 ax[1]=i;
                 ax[2]=j;               
              }
        }
       g <<  ax[0] << "\n";
       int aux=ax[0];
       while(aux)
       {
          aux--;
          ax[1]--;
          ax[2]--;          
       }
    aux = 1;
   while(aux <=ax[0])
      {
         if(aux==a[ax[1]][ax[2]])
             {
              g << a[ax[1]][0] << " ";
              aux++;
              }
         ax[1]++;
         ax[2]++;     
                              
      }
    g.close();    
    return 0;
    
}
