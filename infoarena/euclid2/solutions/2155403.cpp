#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n;
    f>>n;
    for(int i=0, a, b; i<n; i++)
    {
        f>>a>>b;
        while(b)
        {
            int aux=a;
            a=b;
            b=aux%b;
        }
        g<<a<<endl;
    }
    f.close();
    g.close();
    return 0;
}
