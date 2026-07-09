#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
unsigned a,b,i;
int cmmdc(unsigned a, unsigned b)
{ unsigned r;
  r=a%b;
  while(r)
	{ a=b;
	  b=r;
	  r=a%b;
	}
 return b;
}
int main()
{ fin>>i;
  for(unsigned j=0;j<i;j++)
  { fin>>a;
	fin>>b;  
	fout<<cmmdc(a,b)<<"\n";
  }
return 0;
}