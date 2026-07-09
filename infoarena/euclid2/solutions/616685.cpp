#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
using namespace std;

#define INFILE "euclid2.in" 
#define OUTFILE "euclid2.out"


long long int gcd(long long int a, long long int b)
{
  return (b==0 ? a : gcd(b, a%b));
}

int main()
{
  FILE *fin, *fout;
  fopen_s(&fin, INFILE, "r");
  fopen_s(&fout, OUTFILE, "w");
  long long int a, b;
  int t;
  fscanf(fin, "%d", &t);
  while( t-- )
  {
    fscanf(fin, "%lld %lld", &a, &b);
    fprintf(fout, "%lld\n", gcd(a, b));
  }

	
	return 0;
}
