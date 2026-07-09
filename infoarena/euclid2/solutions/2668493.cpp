#include <iostream>
#include <fstream>
#define FIN "euclid2.in"
#define FOUT "euclid2.out"

using namespace std;

typedef unsigned long ulong;

namespace Math {
         
          void Euclid_it(ulong a, ulong b, ulong *p) {

              ulong r;

              while(b){
              	r = a % b;
              	a = b;
              	b = r;
              }

              *p = a;
          }

          ulong Euclid_rec(ulong a, ulong b, ulong *p) {

              if( b == 0 )  {

              	  *p = a;

              } else return Euclid_rec(b, a % b, p);
          }

};

int main(int argc, char const *argv[])
{	
	ifstream fin(FIN);
	ofstream fout(FOUT);

	if(!fin || !fout) {

	   cout<<"Error Opening Files!";

	   return -1;
	}

	int nPairs;
	ulong first, 
	      second, 
	      result;

	fin>>nPairs;

	for(int i = 0; i < nPairs; ++i) {

		fin>>first>>second;

		Math::Euclid_it(first, second, &result);

		fout<<result<<"\n";
	}


	
	return 0;
}