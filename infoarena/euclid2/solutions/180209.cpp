#include<fstream.h>      
#include<math.h>      
int main() {      
ifstream f("euclid2.in");      
ofstream g("euclid2.out");      
long a,b,c,n,i;   
f>>n;   
for(i=0;i<n;i++)      
    {   f>>a>>b;      
    while(b)
	{ c=a%b;
  	  a=b;
	  b=c;
	}      
            
    g<<a<<"\n";   
    }      
f.close();      
g.close();      
return 0;      
}    