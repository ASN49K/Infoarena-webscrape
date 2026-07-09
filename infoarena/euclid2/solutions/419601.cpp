// algoritmul lui euclid.cpp : Defines the entry point for the console application.
//



using namespace std;
#include<fstream>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a, int b)
{  if (b==0)
	return a;
else 
return cmmdc(b,a%b);
	
}

int main()
{ int n,i,a,b;
f>>n;
for(i=0;i<n;i++)
{
f>>a;f>>b;
g<<cmmdc(a,b);
g<<endl;
}

f.close();
g.close();
	return 0;
}

