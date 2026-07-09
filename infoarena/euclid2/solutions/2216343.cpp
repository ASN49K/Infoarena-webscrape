#include <iostream>
using namespace std;
#include<fstream>

unsigned euclid (int a,int b)
{
    if (!b)
        return a;
    else
    euclid(b,a%b);
}


int main ()
{
    int a,b,n;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    while(n)
    {
        f>>a>>b;
        g<<euclid(a,b)<<"\n";
        n--;
    }
    return 0;

}
