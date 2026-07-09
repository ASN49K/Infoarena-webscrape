#include<fstream.h>
int main()  
{long int a,b,n,i,c;  
ifstream f("euclid2.in"); 
ofstream g("euclid2.out");  
f>>n;
for(i=1;i<=n;++i)
{f>>a>>b;  
while(a!=b)  
  { if(a<b){c=a;a=b;b=c;}

 if(a%b==0) a=b; else a%=b; 
    }
if(a==1) g<<0<<'\n'; 
else g<<a<<'\n';}
f.close();  
g.close();  
return 0;}  