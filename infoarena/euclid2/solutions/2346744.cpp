#include <stdio.h>
#include <iostream>
#include <fstream>	
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");	
int cmmdc(int a, int b)
	
{
    if (!b) return a;
	
    return cmmdc(b, a % b);
}
	
 
	
int main()
	
{
	int x,y,n;
	f>>n;
    for (unsigned int i=1; i<=n; i++)
	
    {
	
        f>>x>>y;
		g<<cmmdc(x,y)<<"\n";
	
    }        
	
 	f.close();
 	g.close();
	
    return 0;
	
}
	
 
