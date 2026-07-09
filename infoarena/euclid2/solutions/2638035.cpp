#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a, int b)
{
     if (!b) return a;
     else return euclid(b, a%b);
}

int main()
{
     ifstream intrare("euclid2.in");
     ofstream iesire("euclid2.out");

     int i, a, b;
     intrare >> i;

     while(i--)
     {
          intrare >> a >> b;
          iesire << euclid(a, b) << "\n";
     }

     return 0;
}
