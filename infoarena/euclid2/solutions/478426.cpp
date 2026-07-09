#include <fstream>


using namespace std;

int eu(int a ,int b )
{ long t;
 while (b)
      { t = b;
       b = a %b
       a= t;}
    return a
}

int main ()
{
		ifstream f("euclid2.in");
		ofstream g("euclid2.out");
		long n,a,b;
		f>>n;
		for(int i=0;i<n;i++)
			{f>>a>>b;
				g<<eu(a,b)<<" ";
			}
		
		
		
		
		}