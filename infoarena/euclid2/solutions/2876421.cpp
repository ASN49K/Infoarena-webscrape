#include <fstream>

using namespace std;

long T, a, b;

ifstream in(“euclid2.in”);
ofstream out(“euclid2.out”);

int GCD(long A, long B)
{
 if(!B)
  return A;
 return GCD(B, A%B)
}

int main()
{
 in>>T;
 for(long i =1; i <= T; i++)
 {
  in>>a>>b;
  out<<GCD(a,b);
 }
 return 0;
}