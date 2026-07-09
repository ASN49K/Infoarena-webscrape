#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void calcdiv(unsigned long a, unsigned long b)
{ unsigned long r;
  r=a%b;
  while(r)
   { a=b;
     b=r;
	r=a%b;
   }
  fout<<b<<'\n';
}	

int main()
{ long int i,t;
  unsigned long a,b;
  fin>>t;
  for(i=0;i<t;i++)
   { fin>>a;fin>>b;
     if(!a) fout<<a<<'\n';
	 else if (!b) fout<<b<<'\n';
	       else calcdiv(a,b);
   }
  return 0;
}