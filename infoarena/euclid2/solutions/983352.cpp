#include <fstream>

int T;
long int a, b;

int euclid(int a, int b)
{
    if(!b) return a;
    else return euclid(b, a%b);
}

using namespace std;

int main()
{
    fstream f("euclid2.in", ios::in);
    fstream g("euclid2.out", ios::out);
    f>>T;
    for(int i=1; i<=T; i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<endl;

    }
    f.close();
    g.close();

}
