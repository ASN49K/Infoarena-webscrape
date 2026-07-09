#include <fstream>

using namespace std;

int gcd(int a, int b)
{
    if (b==0)
        return a;
    else
	return gcd(b,a%b);
}

int main(){


  ifstream in("euclid2.in");
  ofstream out("euclid2.out");
  int t,a,b;
  in >>t;
  
  for (int i=0;i<t;i++)
  {
  	
  	in>>a>>b;
  	out<<gcd(a,b)<<"\n";
  }
  
  
  return 0;
}


