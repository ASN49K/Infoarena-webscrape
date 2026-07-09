#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a, b, t, nrP;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> nrP;
    for(int i = 0; i < nrP; i ++)
    {
       f >> a >> b;
       if(a >= b)
       {
         do
         {
            t = a % b;
            a = b;
            b = t;
         }while(t != 0);
         g << a << "\n";
       }
       else
       {
         do
         {
            t = b % a;
            b = a;
            a = t;
         }while(t != 0);
         g  << b << "\n";

       }
    }
    g.close();

    return 0;
}
