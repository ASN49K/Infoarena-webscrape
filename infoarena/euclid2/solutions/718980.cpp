#include <fstream>
using namespace std;
int main()
{int n,i,n1,n2;
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>n;
 for(i=1;i<=n;i++)
 {f>>n1>>n2;
  while(n1!=n2)
     {if(n1>n2)
		 n1=n1-n2;
	  if(n2>n1)
		  n2=n2-n1;
	 }
	g<<n1<<endl;
 }
}