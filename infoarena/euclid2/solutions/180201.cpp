#include<fstream.h>   
#include<math.h>   
int main() {   
ifstream f("euclid2.in");   
ofstream g("euclid2.out");   
long a,b,n,i;
f>>n;
for(i=0;i<n;i++)   
    { 	f>>a>>b;   
	while(a!=b)   
	    if(a>b)   
        	a=a-b;   
    	else   
       	 	b=b-a;   
	if(a==1)   
    		g<<0;   
	else   
    		g<<a;
	}   
f.close();   
g.close();   
return 0;   
}  