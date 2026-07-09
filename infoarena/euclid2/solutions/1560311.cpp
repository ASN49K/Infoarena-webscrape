#include <iostream>
#include <fstream>
using namespace std;

int euclid(int x, int y)
{
    int c;
    while (y) {
        c = x % y;
        x = y;
        y = c;
    }
    return x;
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream gout("euclid2.out");
    unsigned long t,a,b;
    fin>>t;
    while(t!=0)
    {
        fin>>a;
        fin>>b;
        gout<<euclid(a,b)<<endl;
        t--;
    }
    return 0;
}
