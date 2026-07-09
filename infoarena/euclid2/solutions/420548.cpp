#include<fstream.h>
long long T,a,b,d[10001],i,max,j;
int main()
{
    ifstream f("euclid2.in"); f>>T;
    ofstream g("euclid2.out"); 
    for(i=1;i<=T;i++)
    {  f>>a;
       f>>b;
      for(j=1;j<=a/2;j++)
      d[j]=0;
      for(j=1;j<=a/2;j++)
       { if(a%j==0)
           if(b%j==0) d[j]=j;
       }  
        max=0;
       for(j=1;j<=a/2;j++)
         if(d[j]>max) max=d[j];      
         
        g<<max<<'\n';
    }  
   
    return 0;
}
