 #include <fstream.h>  
     
    long a,b,d,t;    
    int main()    
    {    
       ifstream f("euclid2.in");    
       ofstream g("euclid2.out");    
       f>>t;
      for (long i=1;i<=t;i++)
       {
       f>>a>>b;    
       do    
       {    
           d=a%b;    
           a=b;    
           b=d;    
       }    
       while(d);    
       g<<a<<"\n";    
       }      
return 0;    
  }  