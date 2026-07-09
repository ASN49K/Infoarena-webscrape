#include<fstream.h>  
int t,a,b;  
  int euclid(int a,int b)  
      {  
     if(!b)  
        return a;  
      return euclid(b, a%b);  
      }  
  int main()  
  {  
     ifstream fin("euclid2.in"); ofstream fout("euclid2.out");  
     fin>>t;  
     while(t)  
         {  
          t--;  
          fin>>a>>b;  
          fout<<euclid(a,b)<<'\n';  
        }  
   fin.close ();  
   fout.close ();  
   return 0;  
  }  