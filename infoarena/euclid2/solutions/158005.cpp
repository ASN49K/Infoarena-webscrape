#include<fstream.h>   
ifstream f("euclid2.in");   
ofstream g("euclid2.out"); 
  
int cmmdc1(int a, int b)   
{int r;
if(a<b){r=b;b=a; a=r;}      
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
{ int a,b,n,i;   
 f>>n;
 for(i=0;i<n;i++)
  {f>>a>>b;  
   g<<cmmdc1(a,b)<<"\n";}   
 f.close();
 g.close();   
 return 0;   
}  
