// algoritmul lui euclid.cpp : Defines the entry point for the console application.
//



using namespace std;
#include<fstream>
ifstream f("euclid2.in.txt");
ofstream g("euclid2.out.txt");
int cmmdc(int a, int b)
{  if (b==0)
	return a;
else 
return cmmdc(b,a%b);
	
}

int _tmain(int argc, _TCHAR* argv[])
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

