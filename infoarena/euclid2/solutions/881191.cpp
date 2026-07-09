#include <fstream>
using namespace std;
ifstream f("euclid.in"); 
ofstream g("euclid.out");
int a,b,i,n,r;
int main()
{   f>>n;    
	for(i=1; i<=n; i++)    
		{   f>>a>>b;       
			while(b)        
			{   r=a%b;            
				a=b;           
				b=r;       
			}        
		g<<a<<"\n";   
		}
g.close(); 
return 0;
}
