#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int a,b,r;
    ifstream f("euclid2.in");
    ofstream o("euclid2.out");

    f>>a>>b;
    while (b!=0) {
    r = a%b;
    a = b;
    b = r;
    }
    o<<a;
}
