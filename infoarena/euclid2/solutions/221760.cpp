//http://infoarena.ro/problema/euclid2   stare:   punctaj:
#include <fstream.h>

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a,b,n,i;

int euclid(int a,int b)
{
	int c;
	while(b)
	{
		 c = a % b;  
     a = b;  
     b = c;  
  }  
  return a; 
}

int main()
{
	fin>>n;
	for(i=1;i<=n;i++)
	{
		fin>>a>>b;
		fout<<euclid(a,b)<<'\n';
	}
	return 0;
}	