#include<fstream.h>  
#include<stdio.h>  
  

int main()   
{   
ifstream f1("euclid2.in");     

int a,b,c;

f1>>a>>b;
f1.close();

while(b)
{
	c=a%b;
	a=b;
	b=c;
}

ofstream f2("euclid2.out");
f2<<a;
f2.close();

return 0;}   