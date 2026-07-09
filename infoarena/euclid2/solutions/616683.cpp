#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

#define INFILE "euclid2.in" 
#define OUTFILE "euclid2.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

long long gcd(long long a, long long b)
{
  return (b==0 ? a : gcd(b, a%b));
}

int main()
{
  long long a, b;
  int t;
  fin >> t;
  while( t-- )
  {
    fin >> a >> b;
    fout << gcd(a, b) << endl;
  }

	
	return 0;
}
