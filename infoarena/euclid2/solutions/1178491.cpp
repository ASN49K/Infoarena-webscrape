#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

int euclid (int a, int b) {
  if (b == 0)
    return a;
  else 
    return euclid (b, a%b);
}

int main (void) {
  int T, N1, N2;
  ifstream input;
  ofstream output;

  input.open("euclid2.in");
  input >> T;
  assert(T >= 1);
  assert(T <= 100000);
  
  output.open("euclid2.out");
  for (int i = 0; i < T; i++) {
    input >> N1 >> N2;
    assert (N1 >= 2);
    assert (N2 <= 2 * 10^9);
    output << euclid(N1,N2) << '\n';
  }

  input.close();
  output.close();

  return 0;
}


