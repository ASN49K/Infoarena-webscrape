#include<fstream>
using namespace std;
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");
int a,b,r;
int main()
{ f>>a>>b;
  while(b) { r=a%b;
			 a=b;
			 b=r;
		    }
  if(a==1) g<<0;
  else g<<a;
  return 0;
}