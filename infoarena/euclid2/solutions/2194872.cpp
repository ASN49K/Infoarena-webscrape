#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream be("euclid2.in");
    ofstream ki("euclid2.out");
    int a,b;
    be>>a>>b;
    while (a!=b)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    ki<<a;
    return 0;
}
