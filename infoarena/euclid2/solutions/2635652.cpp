#include <iostream>
#include <fstream>

using namespace std;

ifstream i("euclid2.in");
ofstream o("euclid2.out");

int main() {
int T, a, b;
i>> T;
for(int rest; T != 0; T--) {
   i>>a, b;
   while(b != 0) {
    rest = a%b;
    a = b;
    b = rest;
   }
   o<< a <<endl;

}
 return 0;
}
