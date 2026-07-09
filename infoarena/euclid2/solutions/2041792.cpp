#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int a, b;
    ifstream be("euclid2.in");
    be>>a>>b;
    be.close();
    while(a)
    {
        if(a < b)
            swap(a,b);
        a = a % b;
    }
    ofstream ki("euclid2.out");
    ki<<b;
    return 0;
}
