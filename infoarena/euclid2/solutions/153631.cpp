 #include<fstream.h>  
  ifstream f("euclid2.in");  
  ofstream g("euclid2.out");  
   int euclid(int,int);
    
   int main(int a ,int b)  
  {  int T,i;
     f>>T;
     for(i=1;i<=T;i++)
    { f>>a>>b;  
     g<<euclid(a,b)<<' ';g<<"\n";  }
    return 0;  
       }
   int euclid(int a,int b)  
  {   if(b==0) return a;  
        else return euclid(b,a%b);  
  }  
 
