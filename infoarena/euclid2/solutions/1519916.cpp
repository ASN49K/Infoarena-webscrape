#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a, b, t;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> a >> b;
    if(a >= b)
    {
      do
      {
         t = a % b;
         a = b;
         b = t;
      }while(t != 0);
      g << a;
    }
    else
    {
      do
      {
         t = b % a;
         b = a;
         a = t;
      }while(t != 0);
      g  << b;

    }
    g.close();
    return 0;
}
