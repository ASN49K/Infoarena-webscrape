#include<fstream> 
using namespace std; 
ifstream f("euclid2.in"); 
ofstream g("euclid2.out");
int cmmdc(int a, int b) 
{if(a==b) 
	return a; 
else if (a>b) 
	return cmmdc(a-b,b); 
else 
	return cmmdc(a,b-a); 
}
int main() 
{int t,a,b,i; 
f>>t; 
for(i=0;i<t;i++) 
{f>>a; f>>b;
	g<<cmmdc(a,b)<<'\n';}
return 0;
}
