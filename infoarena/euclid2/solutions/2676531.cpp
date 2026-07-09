#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a, b, T;
int Euclid3_0(int a, int b)
{
    if(!b) return a;
    return Euclid3_0(b,a%b);
}
int main()
{

    for(f>>T; T ; --T)
    {
        f>>a>>b;
        g<<Euclid3_0(a,b)<<endl;

    }
    return 0;
}
