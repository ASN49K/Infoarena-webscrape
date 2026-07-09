#include<fstream>
using namespace std;

int cmmdc(int a, int b)
{
  int r;
  while (b!=0)
  {
    r=a%b;
    a=b;
    b=r;
  }
  return a;
}


int main(int nr, char* arg[])
{
	ifstream f;
	ofstream g;
	f.open("euclid2.in",ios::in);
	g.open("euclid2.out",ios::out);
	int t;
	f>>t;
	int a,b;
	for(int i=0;i<t;i++)
	{
	 f>>a>>b;
	 g<<cmmdc(a,b)<<"\n"; 
	 //g<<a<<"---"<<b<<"\n";
	}
	f.close();
	g.close();
}
