#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int x, int y){
        if(y == 0)
            return x;

            return cmmdc(y, x % y);
    }

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int howMany, a, b;
    f >> howMany;

    for(int i = 0; i < howMany; i++)
    {
        f >> a >> b;
        g << cmmdc(a , b) << "/n";
    }
    f.close();
    g.close();
}
