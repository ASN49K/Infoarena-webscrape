#include <iostream>
#include <fstream>

using namespace std;

ifstream i("euclid2.in");
ofstream o("euclid2.out");

unsigned int dvc(unsigned int x, unsigned int y)
{


  while (y != 0)
         {
            int r = x%y;
            x = y;
            y = r;
        }
        return x;
}


int main()
{
     unsigned int t, a, b;
    i>> t;
    while(t--)
    {
        i>> a >> b;
        o<< dvc(a, b) <<endl;



    }
    return 0;
}
