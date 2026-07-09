#include<fstream.h>   
ifstream f("cmmdc.in");   
ofstream g("cmmdc.out"); 
  
int cmmdc1(int a, int b)   
{int r;      
r=a%b;   
while(r)   
 {   
 a=b;   
 b=r;   
 r=a%b;   
 }      
 return b;   
} 
  
int main()   
{ int a,b,n;   
 f>>n;
 for(i=0;i<n;i++)
  {f>>a,b;  
   g<<cmmdc1(a,b);   
 f.close();
 g.close();   
 return 0;   
}  
