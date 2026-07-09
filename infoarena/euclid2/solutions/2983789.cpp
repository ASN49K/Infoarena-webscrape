#include <fstream>
using namespace std;
int T, A, B;
int euclid(int a, int b)
{
    if(!b) return a;
    else
        return euclid(b, a%b);
}
int main()
{
    ifstream f("euclid.in");
    ofstream g("euclid.out");
    f>>T;
    for(int i=0; i<T; i++)
    {
        f>>A>>B;
        g<<euclid(A,B)<<'\n';
    }
g.close();
}
