#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main() {
int T, a, b;
f>> T;
for(int rest; T != 0; T--) {
   f>>a, b;
   while(b != 0) {
    rest = a%b;
    a = b;
    b = rest;
   }
   g<< a <<endl;

}
 return 0;
}
