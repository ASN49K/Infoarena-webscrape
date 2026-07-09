#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int euclid (int a, int b) {
	if (!b)
		return a;
			
	return euclid (b, a % b);
}

int main (int argc, char * argv []) {
  ifstream ins;
  ins.open ("euclid2.in");
  if (!ins) {
    cerr << "invalid file in" << endl;
    exit (1);
  }
  
  ofstream ous;
  ous.open ("euclid2.out");
  if (!ous) {
	cerr << "invalid file out" << endl;
  }

  int n = 0;
  ins >> n;
    
  for (int i = 0 ; i < n ; i ++) {
	// read two numbers
	int a, b;
	ins >> a >> b;
	ous << euclid (a, b) << endl;
  }
  
}
