#include <iostream>
#include <cstdio>
using namespace std;

class Euclid{
 public:
  static long long SolveGCD(long long first_number,
			    long long second_number) {
   if (second_number == 0) {
    return first_number;
   } 
   return Euclid::SolveGCD(second_number, 
			first_number % second_number);
  }
};

int main() {
 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);
 // Testing...
 int T,A,B;
 while (T--) {
  cin >> A >> B;
  cout << Euclid::SolveGCD(A,B) << endl;
 }
 return 0;
}
