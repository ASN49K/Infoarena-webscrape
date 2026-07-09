#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;


int alg_euclid(int x, int y)
{
    int r;
    while(y)
    {
        r = x % y;
        x = y;
        y = r;

    }

    return x;
}

int main()
{
    int T, a, b, i;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>T;
    for(i = 1; i <= T; i++)
    {
          in>>a>>b;
          out<<alg_euclid(a,b)<<"\n";
    }

    return 0;
}
