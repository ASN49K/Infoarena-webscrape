#include <iostream>
#include <fstream>
using namespace std;
int n, x, y;

int euclid(int a, int b) {
    if (!b) return a;
    return euclid(b, a%b);
 }

 int main()
{
   ifstream in("euclid2.in");
   ofstream out("euclid2.out");
   in>>n;
   for (int i = 1; i <= n; ++i) {
       in >> x >> y;
       out << euclid(x, y) << '\n';
   }

}
