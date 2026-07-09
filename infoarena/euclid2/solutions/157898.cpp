#include<fstream.h>   
ifstream f("cmmdc.in");   
ofstream g("cmmdc.out");   
int cmmdc1(int a, int b)   
{int r,aux1=a,aux2=b;   
if(a<b){r=b;b=a; a=r;}   
r=a%b;   
while(r)   
 {   
 a=b;   
 b=r;   
 r=a%b;   
 }   
if(b==1||aux1==aux2) g<<0;   
 else g<<b;   
 return 0;   
}   
int main()   
{ int a,b;   
 f>>a>>b;f.close();   
 cmmdc1(a,b);   
 g.close();   
 return 0;   
}  
