#include <fstream>

using namespace std;

int T;
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
    f>>T;
    for(int i=1; i<=T; i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<endl;
    }

}
