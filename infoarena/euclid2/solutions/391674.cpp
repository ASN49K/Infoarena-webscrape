#include <fstream>
using namespace std;
int main()
{
long n,a,b,r;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>n;
while(n--)
     {
     fin>>a>>b;
	      while (b)
       {
       r=a%b;
       a=b;
       b=r;
       }
     fout<<a<<endl;
     }
return 0;
}