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
        max1[m-1]=1;
        for(i=m-2;i>=0;i--)
        {               
           if(a[i]>a[i+1])
              for(j=i;j<m;j++){
               if(a[i]<=a[j])
                  max1[i]=max1[j]+1;
               else
                 if(j==m-1)
                    max1[i]=1; 
                  }
          else
            max1[i]=max1[i+1]+1;                     
         }
    
   max2[n-1]=1;
        for(i=n-2;i>=0;i--)
        {               
           if(a[i]>a[i+1])
              for(j=i;j<n;j++){
               if(b[i]<=b[j])
                  max2[i]=max2[j]+1;
               else
                 if(j==n-1)
                    max2[i]=1; 
                  }
          else
            max2[i]=max2[i+1]+1;                     
         }
         
         
        
        
        for(i=0;i<m;i++)
          g << max1[i] << " " ;
          g << "\n";
     for(i=0;i<n;i++)
          g << max2[i] << " " ;
          g << "\n";
   
   int m1,m2;
   if(m<n)
   {
      m1=max1[0];
      m2=-1;
      for(i=0;i<m;i++)
      {
         if(m1>max1[i])
             m1=max1[i];
         for(j=0;j<n;j++)
            if(a[i]==b[j]&&m1==max1[i]&&(m2>=max2[j]||m2==-1))
            {
                if(m2==-1)
                  m2=max2[j];
                vect[lungime++]=a[i];
                m1--;
                m2--;                                                 
            }             
             
      }       
   }
   else
     {m2=max2[0];
      m1=-1;
      for(i=0;i<n;i++)
      {
         if(m2>max2[i])
             m2=max2[i];
         for(j=0;j<m;j++)
            if(b[i]==a[j]&&m2==max2[i]&&(m1>=max1[j]||m1==-1))
            {
                if(m1==-1)
                  m1=max1[j];
                vect[lungime++]=b[i];
                
                m1--;
                m2--;                                                 
            }             
            }     
      } 
   g << lungime << "\n";
   for(i=0;i<lungime;i++)
     g << vect[i] << " ";
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
