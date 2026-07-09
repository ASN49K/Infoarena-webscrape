#include <fstream>

int T, i;
long int a, b;

using namespace std;

int euclid(int a, int b)
{
    if(a==b) return a;
    else if(a>b) euclid(a-b, b);
        else euclid(a, b-a);
}

int main()
{
    fstream f("euclid2.in", ios::in);
    fstream g("euclid2.out", ios::out);
    f>>T;
    for(i=1; i<=T; i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<endl;
    }
    f.close();
    g.close();

}
