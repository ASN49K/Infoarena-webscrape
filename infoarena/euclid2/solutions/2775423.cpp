#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n;
    f>>n;
    int a,b;
    while(n--)
    {
        f>>a>>b;
        int r;
        do
        {
            r=a%b;
            a=b;
            b=r;
        }while(b);
        g<<a<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
