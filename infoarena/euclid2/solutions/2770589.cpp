#include <iostream>
#include <fstream>
#define FIN "euclid.in"
#define FOUT "euclid.out"

using namespace std;

int euclid(int a, int b) {

    int r = a % b;

    while( r ) {
      a = b;
      b = r;
      r = a % b;
    }

    return b;
}

int main(int argc, char const *argv[]) {

  int a, b, T;

  ifstream fin(FIN);
  ofstream fout(FOUT);

  for(fin>>T; T; T--) {
       fin>>a>>b;
       fout<<euclid(a,b)<<"\n";
  }

  return 0;
}
