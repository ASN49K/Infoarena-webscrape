
#include <bits/stdc++.h>
using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int gcd ()
{
  int a, b;
  f >> a >> b;
    while(b != 0){
        int r = a % b;
        a = b; b = r;
    }


  return a;
}

int main ()
{

  int m;
  f >> m;
  while (m--)
	{
	  g << gcd () << endl;
	}


  return 0;
}
