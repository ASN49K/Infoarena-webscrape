#include <fstream>

using namespace std;

unsigned long int a, b;

int euclid(int a, int b)
{
    if(!b) return a;
    else return euclid(b, a%b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>a>>a>>b;
    g<<euclid(a, b)<<endl;
    while(f>>a>>b) g<<euclid(a,b)<<endl;
    g.close();
    f.close();
}
