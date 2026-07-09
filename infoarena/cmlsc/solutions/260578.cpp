#include <fstream>

using namespace std;

fstream f;
fstream g;
int m,n;
int a[1024];
int b[1024];
int max1[1024];
int max2[1024];
int i,j;

void lsub()
{
       int lungime=0;
       int vect[1024];
       int k=0;
        max1[m-1]=1;
        for(i=m-2;i>=0;i--)
        {
         if(a[i]>a[i+1])
            max1[i]=max1[i+1];
          else
            max1[i]=max1[i+1]+1;                     
         }
   
   max2[n-1]=1;
        for(i=n-2;i>=0;i--)
        {
         for(j=i;j<m-1;j++)
          if(b[i]>b[i+1])
             max2[i]=max2[i+1];
          else
             max2[i]=max2[i+1]+1;                     
         }
   
    int max,Max;
    
   
    
    if(m<n){
             max = max1[0];
    Max = 0;
     for(i=0;i<m;i++)
     {
       for(j=0;j<n;j++)
          if(a[i]==b[j]&&max==max1[i]&&(Max==max2[j]||Max==0))
            {
               if(Max==0)
                  Max = max2[j];
               vect[k++]=a[i];
               lungime++;
               max--;
               if(max)
                 Max--; 
               break;           
            }
     }   
     }
     else
      {
            max=0;
    Max = max2[0];
     for(i=0;i<n;i++)
       for(j=0;j<m;j++)
          if(b[i]==a[j]&&Max==max2[i]&&(max==max1[j]||max==0))
            {
               if(max==0)
                 max = max1[j];
               vect[k++]=b[i];
               lungime++;
               max--;
               if(max)
               Max--;   
               break;         
            }
     }   
     g << lungime << "\n";
     for(i=0;i<k;i++)
        g << vect[i] << " ";
     g<<"\n";
} 



int main()
{
    f.open("cmlsc.in",fstream::in);
    f >> m >> n;
    for(i=0;i<m;i++)
       f >> a[i]; 
    for(i=0;i<n;i++)
      f>> b[i];       
    f.close();
    
    
    g.open("cmlsc.out",fstream::out);
    lsub();
    g.close();    
    return 0;
    
}
