#include<fstream>
using namespace std;
#define input "euclid2.in"
#define output "euclid2.out"

int main()	
	 {
	 ifstream fin(input);
	 ofstream fout(output);
	 int a,b,t;
	 fin>>t;
	 for(int i=1;i<=t;++i)
		  {
		  fin>>a>>b;
		  while(a*b)
				{
				if(a>b)
					 a%=b;
				else
					 b%=a;
				}
		  fout<<a+b<<"\n";
		  }
	 fin.close();
	 fout.close();
	 return 0;
	 }
