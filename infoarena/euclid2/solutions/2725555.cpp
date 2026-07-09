#include <iostream>
#include <fstream>
using namespace std;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

int euclid(int a, int b)
{
     int c;
    while (b!=0) {
        c = a % b;
        a = b;
        b = c;
    }
    g << a <<endl;
}

int main()
{
    int T;
    int a,b;
    f >>  T;
    for(int i=0;i<=T;i++)
    {
        f >>a >>b;
        euclid(a,b);
    }
    return 0;
}
